


typedef struct {
    int* arr;
    int front;
    int rear;
    int capacity;
} MyCircularQueue;

MyCircularQueue mq;
MyCircularQueue* myCircularQueueCreate(int k) {
    mq.capacity=k;
    mq.front=-1;
    mq.rear=-1;
    mq.arr=(int*)malloc(k*sizeof(int));
    return &mq;
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->front==-1);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (((obj->rear+1)%obj->capacity)==obj->front);
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)) return false;
    if(myCircularQueueIsEmpty(obj)) {
        obj->front=0;
    }
    obj->rear=(obj->rear+1)%obj->capacity;
    obj->arr[obj->rear]=value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return false;
    if(obj->front==obj->rear){
        obj->front=-1;
        obj->rear=-1;
        return true;
    }
    obj->front=(obj->front+1)%obj->capacity;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->arr[obj->front];
    
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)) return -1;
    return obj->arr[obj->rear];
}



void myCircularQueueFree(MyCircularQueue* obj) {
    obj->front=-1;
    obj->rear=-1;
    free(obj->arr);
}
