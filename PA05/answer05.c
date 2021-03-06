#include "answer05.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1


Image * Image_load(const char * filename)
{
  ImageHeader header;
  size_t read;
  Image *tmp_im, *im = NULL;
  
  // open filename
  FILE *fp = fopen(filename, "rb"); 
  int err = fp == NULL;
  if (err) fprintf(stderr, "unable to open file %s!\n", filename);
  
  if (!err) {
    read = fread(&header, sizeof(ImageHeader), 1, fp);
    err = read != 1||
      header.magic_number != ECE264_IMAGE_MAGIC_NUMBER ||
      header.width == 0 ||
      header.height == 0 ||
      header.comment_len == 0;
    if (err) fprintf(stderr, "corrupt header\n");
    
    if(!err) {
      tmp_im = malloc(sizeof(Image));
      err = tmp_im == NULL;
      if (err) fprintf(stderr, "unable to allocate memory\n");
    }
    
    if(!err) {
      tmp_im->width = header.width;
      tmp_im->height = header.height;
      tmp_im->comment = malloc(sizeof(char) * header.comment_len);
      tmp_im->data = malloc(sizeof(char) * (header.width * header.height));
      err = tmp_im->comment == NULL ||
	tmp_im->data == NULL;
    }
    
    if(!err) {
      read = fread(tmp_im->comment, sizeof(char), header.comment_len,fp);
      err = read != header.comment_len ||
	tmp_im->comment[header.comment_len-1] !='\0';
    }
    
    if(!err) {
      read = fread(tmp_im->data, sizeof(char), header.width * header.height, fp);
      err = read != (header.width * header.height);
    }
    
    if(!err) {
      fgetc(fp);
      err = (!feof(fp));
    }

    if(!err) {
      im = tmp_im;
      tmp_im = NULL;
    }
    
    if(tmp_im != NULL) {
      free(tmp_im->comment);
      free(tmp_im->data);
      free(tmp_im);
    }

    if(fp != NULL) {
      fclose(fp);
    }
  }
  return im;
}


int Image_save(const char * filename, Image * image)
{
  int err = FALSE; 
  FILE * fp = NULL;  
  size_t written = 0;
  
  fp = fopen(filename, "w");
  
  ImageHeader header;
  header.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
  header.width = image->width;
  header.height = image->height;
  header.comment_len = strlen(image -> comment) + 1;
  
  if(!err) {  // Write the header
    written = fwrite(&header, sizeof(ImageHeader), 1, fp);
    written = fwrite(image->comment ,sizeof(char),header.comment_len, fp);
    written = fwrite(image->data, sizeof(uint8_t), header.width*header.height, fp);
   
  }
  
  return written;
}
 
void Image_free(Image * image)
{
  free(image->comment);
  free(image->data);
  free(image);
} 

void linearNormalization(int width, int height, uint8_t * intensity)
{
  int max, min;
  int i, len_pixel;
  len_pixel = width * height;
  max = intensity[0];
  min = intensity[0];
  for (i = 0; i < len_pixel; i++) {
    if ( intensity[i] > max){
      max = intensity[i];
    }
    if (intensity[i] < min) {
      min = intensity[i];
    }
  }
  for(i = 0; i < len_pixel; i++) {
    intensity[i] = (intensity[i] - min) * 255.0 / (max - min);
      }
}
