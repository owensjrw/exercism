#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void encrypt(char key[][8], char word[], char arr2[]){
  int wordLen = strlen(word);
  int idx = 0, row1, col1, row2, col2;
  row1 = col1 = row2 = col2 = 8;

  while (idx < (wordLen - 1)){
    for (int i = 0; i < 8; i++){
      for (int j = 0; j < 8; j++){
        if (word[idx] == key[i][j]){
          row1 = i;
          col1 = j;
        }
        if (word[idx + 1] == key[i][j]){
          row2 = i;
          col2 = j;
        }
      }
    }
    if (row1 == 8    ||
       col1 == 8    ||
       row2 == 8    ||
       col2 == 8    ||
       row1 == row2 ||
       col1 == col2 ){
         arr2[idx] = word[idx + 1];
         arr2[idx + 1] = word[idx];
    } else {
         arr2[idx]     = key[row1][col2];
         arr2[idx + 1] = key[row2][col1];
    }
    idx += 2;
    row1 = col1 = row2 = col2 = 8;
  }
  (wordLen % 2) ? (arr2[wordLen-1] = word[wordLen -1]) : (arr2[wordLen] = '\0');
  arr2[wordLen - 1] = '\0';
}

int found(char m[][8], char val){
  for (int r = 0; r < 8; r++){
    for (int c = 0; c < 8; c++){
      if (m[r][c] == val)
      return 1;
    }
  }
return 0;
}

void generate_key(char key[][8]){
  int i, k = 0;
  char temp[64] = { ' ' };
  temp[k++] = ' ';
  temp[k++] = '.';

  for (i = 0; i < 10; i++, k++)
    temp[k] = '0' + i;
  for (i = 0; i < 26; i++, k++)
    temp[k] = 'A' + i;
  for (i = 0; i < 26; i++, k++)
    temp[k] = 'a' + i;
  for (int r = 0; r < 8; r++){
    for (int c = 0; c < 8; c++){
      i = rand() % 64;
      while (found(key, temp[i]) == 1){
        i = rand() % 64;
      }
      key[r][c] = temp[i];
    }
  }
}

int main(){
  char key[8][8];
  char arr2[100];
  char word[100];

  generate_key(key);

  printf("Enter The Word:\n");
  scanf("%s",word);

  encrypt(key,word,arr2);

  printf("\nUSING THESE KEYS :\n\n");
  for (int i = 0 ;i<8;i++){
    for (int j = 0;j<8;j++){
      printf("%c\t",key[i][j]);
    }
    printf("\n");
  }

  printf("The Encyption Of it : %s\n",arr2);
  return 0 ;
}
