#include <stdio.h>
#include <iostream>

/**
 * Author: Ian Blake
 * Date: January 30th, 2018
 * 
 * in memory implentation of basic queue
 */
using namespace std;
class Q {

    public:
        // Creates a FIFO byte queue, returning a handle to it.
        Q * create_queue();

        // Destroy an earlier created byte queue.
        void destroy_queue(Q * q);

        // Adds a new byte to a queue.
        void enqueue_byte(Q * q, unsigned char b);

        // Pops the next byte off the FIFO queue
        unsigned char dequeue_byte(Q * q); 

        int main();

        unsigned char data[2048];
        int top_pointer, bottom_pointer, count;

};

    void on_out_of_memory(){
        printf("%s\n", "Out of memory");
    }

    void on_illegal_operation(){
        printf("%s\n%s\n%s\n", "Operation not allowed",
                "Notifying authorities","Please stand by");
    }

    Q* create_queue(){
        Q* q = new Q;
        unsigned char *new_data = new unsigned char[2048];
        *q->data = new_data[2048];
        q->top_pointer = 0;
        q->bottom_pointer = 0; 

        q->count = 0;
        
        //should get cleaned up at the end of the block anyway, 
        //but better safe than sorry with memory leaks
        delete[] new_data;

        return q;
    }

    void destroy_queue(Q* q){

        //don't delete a null queue, that's silly
        if(q != NULL){
            //*(q->data) = NULL;
            q->top_pointer = 0;
            q->bottom_pointer = 0;
            q = NULL;
        }
    }

    void enqueue_byte(Q* q, unsigned char b){

        if(q->count < 2048){
            q->data[q->top_pointer] = b;
            //allow the queue to wrap around and re-use empty spots if items have been dequeued
            if(q->top_pointer < 2048){
                q->top_pointer += 1;
            }
            else{
                q->top_pointer = 0;
            }
            q->count += 1;
        }
        else{
            on_out_of_memory;
        }
    }

    unsigned char dequeue_byte(Q* q){
        
        if(q->top_pointer != q->bottom_pointer){
            unsigned char byte = q->data[q->bottom_pointer];
            q->bottom_pointer += 1;
            q->count -= 1;
            return byte;
        }
        else{
             on_illegal_operation();
        }

    }