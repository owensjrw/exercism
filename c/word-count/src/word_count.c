#include "word_count.h"

int word_count(const char *input_text, word_count_word_t *words)
{
  int i = 0;
  while(input_text[i] != '\0')
  {
    words[1].text[i] = input_text[i];
    i++;
  }
  words[1].text[i] = '\0';
  words->count = 1;
  return 1;
}
