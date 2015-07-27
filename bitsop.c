/*************************************************************************
  > File Name: bitsop.c
  > Copyright (C) 2013 Wan Ji<wanji@live.com>
  > Created Time: Thu 22 Jan 2015 07:24:54 AM SGT
  > Descriptions: 
 ************************************************************************/

#include <stdint.h>
#include <string.h>
#include <stdio.h>

uint16_t BIT_CNT_MAP[] = \
                         {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, \
                          1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, \
                          1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, \
                          2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, \
                          1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, \
                          2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, \
                          2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, \
                          3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, \
                          1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, \
                          2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, \
                          2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, \
                          3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, \
                          2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, \
                          3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, \
                          3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, \
                          4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};


void hamming(uint8_t * db, uint8_t * qry, int dim, int num, uint16_t * dist) {
  int i, j;
  memset(dist, 0, sizeof(dist[0]) * num);
  for (i=0; i<num; i++) {
    uint8_t * pdb = db + i * dim;
    for (j=0; j<dim; j++) {
      dist[i] += BIT_CNT_MAP[pdb[j] ^ qry[j]];
    }
  }
}
