#include "svmResults.hpp"
#include "consts.h"

float max(float a,float b){
    if (a>=b)
        return a;
    else 
        return b;
}

float min(float a,float b){
    if (a<=b)
        return a;
    else 
        return b;
}

int int_min(int A,int B){
    if(A<B)
        return A;
    else
        return B;
}


float area(float x1,float x2,float y1,float y2){
    return fabs(x1-x2)*fabs(y1-y2);
}

void printResults(svmpoints *head){
    for(svmpoints *node = head->next; node->next!=NULL;node = node->next){
        printf("X1 = %lf,X2= %lf,Y1 = %lf,Y2 = %lf --- scale = %lf --- score = %lf\n",node->x1,node->x2,node->y1,node->y2,node->scale,node->score);
    }
}

void reduceOverlap(svmpoints *head,double tol){

    float xA1,xA2,yA1,yA2;   
    float xB1,xB2,yB1,yB2;
    float SA ,SB, SI; 
    float overlap;
    float weightA;
    float weightB; 
    for(svmpoints *node=head->next;node->next!=NULL;node = node->next){
        for(svmpoints *nodeExam=node->next;nodeExam->next!=NULL;nodeExam = nodeExam->next){
            xA1 = node->x1;
            xA2 = node->x2;
            yA1 = node->y1;
            yA2 = node->y2;
            xB1 = nodeExam->x1;
            xB2 = nodeExam->x2;
            yB1 = nodeExam->y1;
            yB2 = nodeExam->y2;
            
            SA = area(xA1,xA2,yA1,yA2);
            SB = area(xB1,xB2,yB1,yB2);

            if ((xA1 > xB2 || xB1 > xA2) || (yA1 > yB2 || yB2 < yA1)){
                continue;
            }
            float x2=min(xA2,xB2);
            float x1=max(xA1,xB1);
            float y2=min(yA2,yB2);
            float y1=max(yA1,yB1);
            SI = area(x1,x2,y1,y2);
            overlap = SI/min(SA,SB);
            if (overlap > tol){
                if(node->score>nodeExam->score){
                    weightA = 1.0;
                    weightB = 0.0;
                }else {
                    weightA = 0.0;
                    weightB = 1.0;
                }
                node->x1 = xA1*weightA+xB1*weightB;
                node->x2 = xA2*weightA+xB2*weightB;
                node->y1 = yA1*weightA+yB1*weightB;
                node->y2 = yA2*weightA+yB2*weightB;
                node->scale = node->scale*weightA+nodeExam->scale*weightB;
                node->score = node->score*weightA+nodeExam->score*weightB;
                node->lapped++;
                nodeExam->prev->next = nodeExam->next;
                nodeExam->next->prev = nodeExam->prev;
                free(nodeExam);
            }
        }
    }
}

void addNode(int x, int y, double scale,double score,int iter,svmpoints *head){
    svmpoints *newNode = (svmpoints*)malloc(sizeof(svmpoints));;
    newNode->x1 = (x*WINDOWSTRIDEX)/scale;
    newNode->x2 = (x*WINDOWSTRIDEX+64)/scale;
    newNode->y1 = (y*WINDOWSTRIDEY)/scale;
    newNode->y2  =(y*WINDOWSTRIDEY+128)/scale;
    newNode->scale = scale;
    newNode->score = score;
    newNode->lapped = 0;
    newNode->iter = iter;
    newNode->next = head->next;
    newNode->prev = head;
    if(head->next != NULL)
        head->next->prev = newNode;
    head->next = newNode;
}

void draw(svmpoints *head, Mat drawImage){
    
    int ibound;
    int jbound;
    Vec3b pixel;
    pixel[0] = 0;
    pixel[1] = 255;
    pixel[2] = 0;
    char msg[50];  
    for(svmpoints *node = head->next; node->next!=NULL;node = node->next){
        if (node->lapped >1){
            ibound = node->y2-node->y1;
            jbound = node->x2-node->x1;
            for (int i=0;i<ibound;i++){
                for(int j=0;j<jbound;j++){
                    if(i==0 || i== ibound - 1 || j==0 || j == jbound-1){
                            drawImage.at<Vec3b>(int_min(node->y1+i,drawImage.rows),int_min(node->x1+j,drawImage.cols)) = pixel;
                    }
                }
            }
            sprintf(msg,"Score:%.0lf - Scale:%d",node->score,node->iter);
            putText(drawImage, msg, cvPoint(node->x1,node->y2-4), FONT_HERSHEY_SIMPLEX, 0.3, cvScalar(0,0,255), 1, CV_AA);
        }
    }
}

void readImage(Mat _img ,unsigned char *image,int border){

    int width = _img.cols + 2 * border;

    int j = width + border;    
    for(int r = 0; r < _img.rows; ++r) {
        for(int c = 0; c < _img.cols; ++c, j++) {
            image[j] = _img.at<unsigned char>(r,c);
        }
        j += 2 * border;    //Shift 2 border pixels
    }
}
