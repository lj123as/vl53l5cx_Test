/**
  ******************************************************************************
  * @file           : data_show.c
  * @brief          : source file for the print data
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 .
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
*/

#include "data_show.h"

#if 0
void print_result(VL53L5CX_ResultsData *Result)
{
  int8_t i, j, k, l;
  uint8_t zones_per_line;

  zones_per_line = ((Profile.RangingProfile == RS_PROFILE_8x8_AUTONOMOUS) ||
         (Profile.RangingProfile == RS_PROFILE_8x8_CONTINUOUS)) ? 8 : 4;

  display_commands_banner();

  printf("Cell Format :\n\n");
  for (l = 0; l < VL53L5CX_NB_TARGET_PER_ZONE; l++)
  {
    printf(" \033[38;5;10m%20s\033[0m : %20s\n", "Distance [mm]", "Status");
    if ((Profile.EnableAmbient != 0) || (Profile.EnableSignal != 0))
    {
      printf(" %20s : %20s\n", "Signal [kcps/spad]", "Ambient [kcps/spad]");
    }
  }

  printf("\n\n");

  for (j = 0; j < Result->NumberOfZones; j += zones_per_line)
  {
    for (i = 0; i < zones_per_line; i++) /* number of zones per line */
      printf(" -----------------");
    printf("\n");

    for (i = 0; i < zones_per_line; i++)
      printf("|                 ");
    printf("|\n");

    for (l = 0; l < VL53L5CX_NB_TARGET_PER_ZONE; l++)
    {
      /* Print distance and status */
      for (k = (zones_per_line - 1); k >= 0; k--)
      {
        if (Result->ZoneResult[j+k].NumberOfTargets > 0)
          printf("| \033[38;5;10m%5ld\033[0m  :  %5ld ",
              (long)Result->ZoneResult[j+k].Distance[l],
              (long)Result->ZoneResult[j+k].Status[l]);
        else
          printf("| %5s  :  %5s ", "X", "X");
      }
      printf("|\n");

      if ((Profile.EnableAmbient != 0) || (Profile.EnableSignal != 0))
      {
        /* Print Signal and Ambient */
        for (k = (zones_per_line - 1); k >= 0; k--)
        {
          if (Result->ZoneResult[j+k].NumberOfTargets > 0)
          {
            if (Profile.EnableSignal != 0)
              printf("| %5ld  :  ", (long)Result->ZoneResult[j+k].Signal[l]);
            else
              printf("| %5s  :  ", "X");

            if (Profile.EnableAmbient != 0)
              printf("%5ld ", (long)Result->ZoneResult[j+k].Ambient[l]);
            else
              printf("%5s ", "X");
          }
          else
            printf("| %5s  :  %5s ", "X", "X");
        }
        printf("|\n");
      }
    }
  }

  for (i = 0; i < zones_per_line; i++)
    printf(" -----------------");
  printf("\n");
}
#endif


