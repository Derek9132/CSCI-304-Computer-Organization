#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decoding(char *str){
    char *ptr = str;
    char *begin, *end;
    begin = str;
    end = NULL;
    int full_len = strlen(str);
    char last = *(ptr + full_len - 1);
    if (!(isalpha(last)))
    {
      while (*ptr != '\0') {
              if (isalpha(*ptr)) {
                  char cap;
                  cap = toupper(*ptr);
                  *ptr = cap;
                  ptr++;
              } else {
                  end = ptr - 1;
                  int len = abs(end - begin) + 1;
                  reverse(begin, end, len);
                  while ((*ptr != '\0') && (!(isalpha(*ptr)))) {
                    ptr++;
                  }
                  begin = ptr;
              }
      }
    }
    else
    {
        int i = 0;
        for (i = 0; i < full_len + 1; i++)
        {
          if (isalpha(*ptr)) {
            char cap;
            cap = toupper(*ptr);
            *ptr = cap;
            ptr++;
          } else {
            end = ptr - 1;
            int len = abs(end - begin) + 1;
            reverse(begin, end, len);
            while ((*ptr != '\0') && (!(isalpha(*ptr)))) {
              ptr++;
            }
            begin = ptr;
            }
        }

    }
   remove_underscore(str);
}


reverse(char *ptr_start, char *ptr_end, int length)
{
    int i = 0;
    for (i = 0; i < length/2; i++)
    {
        char to_swap = *ptr_end;
        *ptr_end = *ptr_start;
        *ptr_start = to_swap;
        ptr_start++;
        ptr_end--;
    }

}

void remove_underscore(char *str)
{
    char *ptr = str;;
    while (*ptr != '\0')
    {
        if (*ptr == '_')
        {
            *ptr = ' ';
        }
        ptr++;
    }
}


int main(){
        FILE *fin, *fout;
        fin = fopen("lab1p3in", "r");
        if (!fin){
                printf("Input file does not exist.\n");
                return 0;
        }

        fout = fopen("lab1p3out", "w");
        if (!fout){
                printf("Output file does not exist.\n");
                return 0;
        }

        char temp[100];

        while(fgets(temp, 100, fin) != NULL){
                decoding(temp);
                fprintf(fout, temp);
        }

        fclose(fin);
        fclose(fout);
        return 1;
}



