#ifndef Q_H
#define Q_H

/**
 * Author: Ian Blake
 * Date: January 30th, 2018
 * 
 * in memory implentation of basic queue
 */
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

#endif