#include "../my_ls.h"

void reverse_array(struct file_entry array[], int count) {
        for (int i = 0; i < count / 2; i++) {
        struct file_entry temp = array[i];
        array[i] = array[count - i - 1];
        array[count - i - 1] = temp;
    }
}