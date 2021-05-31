#include "word_count.h"

int get_word(const char* input_text, word_count_word_t* words, int i, int w_num)
{
  int word_len = 0;
  for(uint8_t c = input_text[i];
    ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '\'') || (c == '-')); i++)
  {
    words[w_num].text[i] = tolower(c);
    word_len++;
  }
  words[w_num].text[i] = '\0';
  return word_len;
}

int word_count(const char *input_text, word_count_word_t *words)
{
  uint8_t c = 0;
  uint8_t w_num = 0;
  int i = 0;

  while(c != '\0')
  {
    c = input_text[i];
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z' ))
    {
      i += get_word(const char* input_text, word_count_word_t* words, int i, int w_num);
    }
  }
  return i;
}
