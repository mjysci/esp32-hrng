# ESP32-WROOM-32UE RNG Benchmark

## esp_fill_random

```sh
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |           filename             |rands/second|
 file_input_raw|                  esp_random.bin|  8.10e+07  |
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.33643189|  PASSED  
      diehard_operm5|   0|   1000000|     100|0.94160721|  PASSED  
  diehard_rank_32x32|   0|     40000|     100|0.17402545|  PASSED  
# The file file_input_raw was rewound 1 times
    diehard_rank_6x8|   0|    100000|     100|0.34011143|  PASSED  
# The file file_input_raw was rewound 1 times
   diehard_bitstream|   0|   2097152|     100|0.79145516|  PASSED  
# The file file_input_raw was rewound 2 times
        diehard_opso|   0|   2097152|     100|0.53726236|  PASSED  
# The file file_input_raw was rewound 2 times
        diehard_oqso|   0|   2097152|     100|0.10551815|  PASSED  
# The file file_input_raw was rewound 2 times
         diehard_dna|   0|   2097152|     100|0.54353569|  PASSED  
# The file file_input_raw was rewound 2 times
diehard_count_1s_str|   0|    256000|     100|0.55669454|  PASSED  
# The file file_input_raw was rewound 3 times
diehard_count_1s_byt|   0|    256000|     100|0.38545208|  PASSED  
# The file file_input_raw was rewound 3 times
 diehard_parking_lot|   0|     12000|     100|0.66609484|  PASSED  
# The file file_input_raw was rewound 3 times
    diehard_2dsphere|   2|      8000|     100|0.35382336|  PASSED  
# The file file_input_raw was rewound 3 times
    diehard_3dsphere|   3|      4000|     100|0.62216661|  PASSED  
# The file file_input_raw was rewound 4 times
     diehard_squeeze|   0|    100000|     100|0.41979258|  PASSED  
# The file file_input_raw was rewound 4 times
        diehard_sums|   0|       100|     100|0.07583272|  PASSED  
# The file file_input_raw was rewound 4 times
        diehard_runs|   0|    100000|     100|0.01984571|  PASSED  
        diehard_runs|   0|    100000|     100|0.00534257|  PASSED  
# The file file_input_raw was rewound 4 times
       diehard_craps|   0|    200000|     100|0.45530313|  PASSED  
       diehard_craps|   0|    200000|     100|0.99558351|   WEAK   
# The file file_input_raw was rewound 12 times
 marsaglia_tsang_gcd|   0|  10000000|     100|0.63694331|  PASSED  
 marsaglia_tsang_gcd|   0|  10000000|     100|0.68112778|  PASSED  
# The file file_input_raw was rewound 12 times
         sts_monobit|   1|    100000|     100|0.75816177|  PASSED  
# The file file_input_raw was rewound 12 times
            sts_runs|   2|    100000|     100|0.97697631|  PASSED  
# The file file_input_raw was rewound 12 times
          sts_serial|   1|    100000|     100|0.51940767|  PASSED  
          sts_serial|   2|    100000|     100|0.29321506|  PASSED  
          sts_serial|   3|    100000|     100|0.07382218|  PASSED  
          sts_serial|   3|    100000|     100|0.17642099|  PASSED  
          sts_serial|   4|    100000|     100|0.59515245|  PASSED  
          sts_serial|   4|    100000|     100|0.04904569|  PASSED  
          sts_serial|   5|    100000|     100|0.18892480|  PASSED  
          sts_serial|   5|    100000|     100|0.86476607|  PASSED  
          sts_serial|   6|    100000|     100|0.80828823|  PASSED  
          sts_serial|   6|    100000|     100|0.86177555|  PASSED  
          sts_serial|   7|    100000|     100|0.19579030|  PASSED  
          sts_serial|   7|    100000|     100|0.24132329|  PASSED  
          sts_serial|   8|    100000|     100|0.11257975|  PASSED  
          sts_serial|   8|    100000|     100|0.26883375|  PASSED  
          sts_serial|   9|    100000|     100|0.21051261|  PASSED  
          sts_serial|   9|    100000|     100|0.32966514|  PASSED  
          sts_serial|  10|    100000|     100|0.53924959|  PASSED  
          sts_serial|  10|    100000|     100|0.41381102|  PASSED  
          sts_serial|  11|    100000|     100|0.26384357|  PASSED  
          sts_serial|  11|    100000|     100|0.98832297|  PASSED  
          sts_serial|  12|    100000|     100|0.96802394|  PASSED  
          sts_serial|  12|    100000|     100|0.99893989|   WEAK   
          sts_serial|  13|    100000|     100|0.70939682|  PASSED  
          sts_serial|  13|    100000|     100|0.99964896|   WEAK   
          sts_serial|  14|    100000|     100|0.54799496|  PASSED  
          sts_serial|  14|    100000|     100|0.93367617|  PASSED  
          sts_serial|  15|    100000|     100|0.39685929|  PASSED  
          sts_serial|  15|    100000|     100|0.53332594|  PASSED  
          sts_serial|  16|    100000|     100|0.34391468|  PASSED  
          sts_serial|  16|    100000|     100|0.87502199|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   1|    100000|     100|0.94183007|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   2|    100000|     100|0.41333347|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   3|    100000|     100|0.73702140|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   4|    100000|     100|0.38500354|  PASSED  
# The file file_input_raw was rewound 13 times
         rgb_bitdist|   5|    100000|     100|0.62266545|  PASSED  
# The file file_input_raw was rewound 13 times
         rgb_bitdist|   6|    100000|     100|0.53465912|  PASSED  
# The file file_input_raw was rewound 14 times
         rgb_bitdist|   7|    100000|     100|0.35246254|  PASSED  
# The file file_input_raw was rewound 14 times
         rgb_bitdist|   8|    100000|     100|0.79455255|  PASSED  
# The file file_input_raw was rewound 15 times
         rgb_bitdist|   9|    100000|     100|0.31626604|  PASSED  
# The file file_input_raw was rewound 16 times
         rgb_bitdist|  10|    100000|     100|0.92294591|  PASSED  
# The file file_input_raw was rewound 17 times
         rgb_bitdist|  11|    100000|     100|0.04873545|  PASSED  
# The file file_input_raw was rewound 18 times
         rgb_bitdist|  12|    100000|     100|0.36313603|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   2|     10000|    1000|0.89010389|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   3|     10000|    1000|0.72502530|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   4|     10000|    1000|0.09784028|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   5|     10000|    1000|0.01934430|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   2|    100000|     100|0.89120454|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   3|    100000|     100|0.91489705|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   4|    100000|     100|0.60186156|  PASSED  
# The file file_input_raw was rewound 19 times
    rgb_permutations|   5|    100000|     100|0.18667222|  PASSED  
# The file file_input_raw was rewound 19 times
      rgb_lagged_sum|   0|   1000000|     100|0.10928368|  PASSED  
# The file file_input_raw was rewound 20 times
      rgb_lagged_sum|   1|   1000000|     100|0.28457351|  PASSED  
# The file file_input_raw was rewound 21 times
      rgb_lagged_sum|   2|   1000000|     100|0.14565593|  PASSED  
# The file file_input_raw was rewound 22 times
      rgb_lagged_sum|   3|   1000000|     100|0.32538130|  PASSED  
# The file file_input_raw was rewound 24 times
      rgb_lagged_sum|   4|   1000000|     100|0.71528525|  PASSED  
# The file file_input_raw was rewound 26 times
      rgb_lagged_sum|   5|   1000000|     100|0.49654442|  PASSED  
# The file file_input_raw was rewound 29 times
      rgb_lagged_sum|   6|   1000000|     100|0.48174528|  PASSED  
# The file file_input_raw was rewound 32 times
      rgb_lagged_sum|   7|   1000000|     100|0.06207090|  PASSED  
# The file file_input_raw was rewound 35 times
      rgb_lagged_sum|   8|   1000000|     100|0.42696618|  PASSED  
# The file file_input_raw was rewound 39 times
      rgb_lagged_sum|   9|   1000000|     100|0.53142890|  PASSED  
# The file file_input_raw was rewound 43 times
      rgb_lagged_sum|  10|   1000000|     100|0.39379659|  PASSED  
# The file file_input_raw was rewound 48 times
      rgb_lagged_sum|  11|   1000000|     100|0.19821071|  PASSED  
# The file file_input_raw was rewound 53 times
      rgb_lagged_sum|  12|   1000000|     100|0.02257756|  PASSED  
# The file file_input_raw was rewound 58 times
      rgb_lagged_sum|  13|   1000000|     100|0.54823208|  PASSED  
# The file file_input_raw was rewound 63 times
      rgb_lagged_sum|  14|   1000000|     100|0.00772446|  PASSED  
# The file file_input_raw was rewound 69 times
      rgb_lagged_sum|  15|   1000000|     100|0.00003813|   WEAK   
# The file file_input_raw was rewound 76 times
      rgb_lagged_sum|  16|   1000000|     100|0.90300299|  PASSED  
# The file file_input_raw was rewound 82 times
      rgb_lagged_sum|  17|   1000000|     100|0.17609359|  PASSED  
# The file file_input_raw was rewound 89 times
      rgb_lagged_sum|  18|   1000000|     100|0.00436004|   WEAK   
# The file file_input_raw was rewound 97 times
      rgb_lagged_sum|  19|   1000000|     100|0.15213965|  PASSED  
# The file file_input_raw was rewound 105 times
      rgb_lagged_sum|  20|   1000000|     100|0.35257116|  PASSED  
# The file file_input_raw was rewound 113 times
      rgb_lagged_sum|  21|   1000000|     100|0.23325505|  PASSED  
# The file file_input_raw was rewound 121 times
      rgb_lagged_sum|  22|   1000000|     100|0.33041206|  PASSED  
# The file file_input_raw was rewound 130 times
      rgb_lagged_sum|  23|   1000000|     100|0.16351778|  PASSED  
# The file file_input_raw was rewound 140 times
      rgb_lagged_sum|  24|   1000000|     100|0.99962910|   WEAK   
# The file file_input_raw was rewound 149 times
      rgb_lagged_sum|  25|   1000000|     100|0.19617172|  PASSED  
# The file file_input_raw was rewound 159 times
      rgb_lagged_sum|  26|   1000000|     100|0.19829320|  PASSED  
# The file file_input_raw was rewound 170 times
      rgb_lagged_sum|  27|   1000000|     100|0.41618818|  PASSED  
# The file file_input_raw was rewound 181 times
      rgb_lagged_sum|  28|   1000000|     100|0.60385611|  PASSED  
# The file file_input_raw was rewound 192 times
      rgb_lagged_sum|  29|   1000000|     100|0.98406577|  PASSED  
# The file file_input_raw was rewound 203 times
      rgb_lagged_sum|  30|   1000000|     100|0.03651287|  PASSED  
# The file file_input_raw was rewound 215 times
      rgb_lagged_sum|  31|   1000000|     100|0.03460686|  PASSED  
# The file file_input_raw was rewound 228 times
      rgb_lagged_sum|  32|   1000000|     100|0.91393364|  PASSED  
# The file file_input_raw was rewound 228 times
     rgb_kstest_test|   0|     10000|    1000|0.31150071|  PASSED  
# The file file_input_raw was rewound 228 times
     dab_bytedistrib|   0|  51200000|       1|0.79428083|  PASSED  
# The file file_input_raw was rewound 228 times
             dab_dct| 256|     50000|       1|0.52299346|  PASSED  
Preparing to run test 207.  ntuple = 0
# The file file_input_raw was rewound 229 times
        dab_filltree|  32|  15000000|       1|0.75949697|  PASSED  
        dab_filltree|  32|  15000000|       1|0.63876985|  PASSED  
Preparing to run test 208.  ntuple = 0
# The file file_input_raw was rewound 229 times
       dab_filltree2|   0|   5000000|       1|0.96888765|  PASSED  
       dab_filltree2|   1|   5000000|       1|0.68989170|  PASSED  
Preparing to run test 209.  ntuple = 0
# The file file_input_raw was rewound 229 times
        dab_monobit2|  12|  65000000|       1|0.85648614|  PASSED
```

## csprng_fill_random

```sh
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |           filename             |rands/second|
 file_input_raw|                   csprng_v1.bin|  8.22e+07  |
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.86374846|  PASSED  
      diehard_operm5|   0|   1000000|     100|0.51558673|  PASSED  
  diehard_rank_32x32|   0|     40000|     100|0.73396589|  PASSED  
# The file file_input_raw was rewound 1 times
    diehard_rank_6x8|   0|    100000|     100|0.19704063|  PASSED  
# The file file_input_raw was rewound 1 times
   diehard_bitstream|   0|   2097152|     100|0.97076955|  PASSED  
# The file file_input_raw was rewound 2 times
        diehard_opso|   0|   2097152|     100|0.61336728|  PASSED  
# The file file_input_raw was rewound 2 times
        diehard_oqso|   0|   2097152|     100|0.08707342|  PASSED  
# The file file_input_raw was rewound 2 times
         diehard_dna|   0|   2097152|     100|0.32984589|  PASSED  
# The file file_input_raw was rewound 2 times
diehard_count_1s_str|   0|    256000|     100|0.80758396|  PASSED  
# The file file_input_raw was rewound 3 times
diehard_count_1s_byt|   0|    256000|     100|0.15773410|  PASSED  
# The file file_input_raw was rewound 3 times
 diehard_parking_lot|   0|     12000|     100|0.37143226|  PASSED  
# The file file_input_raw was rewound 3 times
    diehard_2dsphere|   2|      8000|     100|0.38043775|  PASSED  
# The file file_input_raw was rewound 3 times
    diehard_3dsphere|   3|      4000|     100|0.23856015|  PASSED  
# The file file_input_raw was rewound 4 times
     diehard_squeeze|   0|    100000|     100|0.61692763|  PASSED  
# The file file_input_raw was rewound 4 times
        diehard_sums|   0|       100|     100|0.87037476|  PASSED  
# The file file_input_raw was rewound 4 times
        diehard_runs|   0|    100000|     100|0.92171628|  PASSED  
        diehard_runs|   0|    100000|     100|0.95449005|  PASSED  
# The file file_input_raw was rewound 4 times
       diehard_craps|   0|    200000|     100|0.57397521|  PASSED  
       diehard_craps|   0|    200000|     100|0.16998692|  PASSED  
# The file file_input_raw was rewound 12 times
 marsaglia_tsang_gcd|   0|  10000000|     100|0.77715934|  PASSED  
 marsaglia_tsang_gcd|   0|  10000000|     100|0.00101109|   WEAK   
# The file file_input_raw was rewound 12 times
         sts_monobit|   1|    100000|     100|0.63803816|  PASSED  
# The file file_input_raw was rewound 12 times
            sts_runs|   2|    100000|     100|0.80634166|  PASSED  
# The file file_input_raw was rewound 12 times
          sts_serial|   1|    100000|     100|0.63290588|  PASSED  
          sts_serial|   2|    100000|     100|0.53789376|  PASSED  
          sts_serial|   3|    100000|     100|0.64484101|  PASSED  
          sts_serial|   3|    100000|     100|0.50772706|  PASSED  
          sts_serial|   4|    100000|     100|0.13178387|  PASSED  
          sts_serial|   4|    100000|     100|0.07746109|  PASSED  
          sts_serial|   5|    100000|     100|0.32101960|  PASSED  
          sts_serial|   5|    100000|     100|0.60937677|  PASSED  
          sts_serial|   6|    100000|     100|0.34015788|  PASSED  
          sts_serial|   6|    100000|     100|0.70641899|  PASSED  
          sts_serial|   7|    100000|     100|0.51526629|  PASSED  
          sts_serial|   7|    100000|     100|0.80948800|  PASSED  
          sts_serial|   8|    100000|     100|0.67021974|  PASSED  
          sts_serial|   8|    100000|     100|0.08749878|  PASSED  
          sts_serial|   9|    100000|     100|0.92553084|  PASSED  
          sts_serial|   9|    100000|     100|0.63254305|  PASSED  
          sts_serial|  10|    100000|     100|0.59759688|  PASSED  
          sts_serial|  10|    100000|     100|0.99238903|  PASSED  
          sts_serial|  11|    100000|     100|0.36816239|  PASSED  
          sts_serial|  11|    100000|     100|0.84505658|  PASSED  
          sts_serial|  12|    100000|     100|0.90932178|  PASSED  
          sts_serial|  12|    100000|     100|0.91764702|  PASSED  
          sts_serial|  13|    100000|     100|0.84143458|  PASSED  
          sts_serial|  13|    100000|     100|0.43017540|  PASSED  
          sts_serial|  14|    100000|     100|0.49682479|  PASSED  
          sts_serial|  14|    100000|     100|0.38644965|  PASSED  
          sts_serial|  15|    100000|     100|0.91791064|  PASSED  
          sts_serial|  15|    100000|     100|0.40430900|  PASSED  
          sts_serial|  16|    100000|     100|0.85619343|  PASSED  
          sts_serial|  16|    100000|     100|0.61522063|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   1|    100000|     100|0.16341699|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   2|    100000|     100|0.56603622|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   3|    100000|     100|0.77976775|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   4|    100000|     100|0.35133909|  PASSED  
# The file file_input_raw was rewound 13 times
         rgb_bitdist|   5|    100000|     100|0.71288200|  PASSED  
# The file file_input_raw was rewound 13 times
         rgb_bitdist|   6|    100000|     100|0.01393220|  PASSED  
# The file file_input_raw was rewound 14 times
         rgb_bitdist|   7|    100000|     100|0.07076119|  PASSED  
# The file file_input_raw was rewound 14 times
         rgb_bitdist|   8|    100000|     100|0.14656021|  PASSED  
# The file file_input_raw was rewound 15 times
         rgb_bitdist|   9|    100000|     100|0.63587211|  PASSED  
# The file file_input_raw was rewound 16 times
         rgb_bitdist|  10|    100000|     100|0.59790900|  PASSED  
# The file file_input_raw was rewound 17 times
         rgb_bitdist|  11|    100000|     100|0.41513461|  PASSED  
# The file file_input_raw was rewound 18 times
         rgb_bitdist|  12|    100000|     100|0.50888379|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   2|     10000|    1000|0.03515568|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   3|     10000|    1000|0.25133561|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   4|     10000|    1000|0.98270654|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   5|     10000|    1000|0.06570883|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   2|    100000|     100|0.87556296|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   3|    100000|     100|0.99255921|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   4|    100000|     100|0.87808212|  PASSED  
# The file file_input_raw was rewound 19 times
    rgb_permutations|   5|    100000|     100|0.37580959|  PASSED  
# The file file_input_raw was rewound 19 times
      rgb_lagged_sum|   0|   1000000|     100|0.94654621|  PASSED  
# The file file_input_raw was rewound 20 times
      rgb_lagged_sum|   1|   1000000|     100|0.79441355|  PASSED  
# The file file_input_raw was rewound 21 times
      rgb_lagged_sum|   2|   1000000|     100|0.79244882|  PASSED  
# The file file_input_raw was rewound 22 times
      rgb_lagged_sum|   3|   1000000|     100|0.01839998|  PASSED  
# The file file_input_raw was rewound 24 times
      rgb_lagged_sum|   4|   1000000|     100|0.53606451|  PASSED  
# The file file_input_raw was rewound 26 times
      rgb_lagged_sum|   5|   1000000|     100|0.72022159|  PASSED  
# The file file_input_raw was rewound 29 times
      rgb_lagged_sum|   6|   1000000|     100|0.27275888|  PASSED  
# The file file_input_raw was rewound 32 times
      rgb_lagged_sum|   7|   1000000|     100|0.18401757|  PASSED  
# The file file_input_raw was rewound 35 times
      rgb_lagged_sum|   8|   1000000|     100|0.21516124|  PASSED  
# The file file_input_raw was rewound 39 times
      rgb_lagged_sum|   9|   1000000|     100|0.09843183|  PASSED  
# The file file_input_raw was rewound 43 times
      rgb_lagged_sum|  10|   1000000|     100|0.25229654|  PASSED  
# The file file_input_raw was rewound 48 times
      rgb_lagged_sum|  11|   1000000|     100|0.10832452|  PASSED  
# The file file_input_raw was rewound 53 times
      rgb_lagged_sum|  12|   1000000|     100|0.22819048|  PASSED  
# The file file_input_raw was rewound 58 times
      rgb_lagged_sum|  13|   1000000|     100|0.42977193|  PASSED  
# The file file_input_raw was rewound 63 times
      rgb_lagged_sum|  14|   1000000|     100|0.57665817|  PASSED  
# The file file_input_raw was rewound 69 times
      rgb_lagged_sum|  15|   1000000|     100|0.85241747|  PASSED  
# The file file_input_raw was rewound 76 times
      rgb_lagged_sum|  16|   1000000|     100|0.94708820|  PASSED  
# The file file_input_raw was rewound 82 times
      rgb_lagged_sum|  17|   1000000|     100|0.56821610|  PASSED  
# The file file_input_raw was rewound 89 times
      rgb_lagged_sum|  18|   1000000|     100|0.76717992|  PASSED  
# The file file_input_raw was rewound 97 times
      rgb_lagged_sum|  19|   1000000|     100|0.60845497|  PASSED  
# The file file_input_raw was rewound 105 times
      rgb_lagged_sum|  20|   1000000|     100|0.99596358|   WEAK   
# The file file_input_raw was rewound 113 times
      rgb_lagged_sum|  21|   1000000|     100|0.85606358|  PASSED  
# The file file_input_raw was rewound 121 times
      rgb_lagged_sum|  22|   1000000|     100|0.29901211|  PASSED  
# The file file_input_raw was rewound 130 times
      rgb_lagged_sum|  23|   1000000|     100|0.67191379|  PASSED  
# The file file_input_raw was rewound 140 times
      rgb_lagged_sum|  24|   1000000|     100|0.26049669|  PASSED  
# The file file_input_raw was rewound 149 times
      rgb_lagged_sum|  25|   1000000|     100|0.81345060|  PASSED  
# The file file_input_raw was rewound 159 times
      rgb_lagged_sum|  26|   1000000|     100|0.74183056|  PASSED  
# The file file_input_raw was rewound 170 times
      rgb_lagged_sum|  27|   1000000|     100|0.97442780|  PASSED  
# The file file_input_raw was rewound 181 times
      rgb_lagged_sum|  28|   1000000|     100|0.74413516|  PASSED  
# The file file_input_raw was rewound 192 times
      rgb_lagged_sum|  29|   1000000|     100|0.73376773|  PASSED  
# The file file_input_raw was rewound 203 times
      rgb_lagged_sum|  30|   1000000|     100|0.85785894|  PASSED  
# The file file_input_raw was rewound 215 times
      rgb_lagged_sum|  31|   1000000|     100|0.08589181|  PASSED  
# The file file_input_raw was rewound 228 times
      rgb_lagged_sum|  32|   1000000|     100|0.94214011|  PASSED  
# The file file_input_raw was rewound 228 times
     rgb_kstest_test|   0|     10000|    1000|0.13691401|  PASSED  
# The file file_input_raw was rewound 228 times
     dab_bytedistrib|   0|  51200000|       1|0.74935500|  PASSED  
# The file file_input_raw was rewound 228 times
             dab_dct| 256|     50000|       1|0.85796597|  PASSED  
Preparing to run test 207.  ntuple = 0
# The file file_input_raw was rewound 229 times
        dab_filltree|  32|  15000000|       1|0.66741765|  PASSED  
        dab_filltree|  32|  15000000|       1|0.62830447|  PASSED  
Preparing to run test 208.  ntuple = 0
# The file file_input_raw was rewound 229 times
       dab_filltree2|   0|   5000000|       1|0.96962048|  PASSED  
       dab_filltree2|   1|   5000000|       1|0.83089057|  PASSED  
Preparing to run test 209.  ntuple = 0
# The file file_input_raw was rewound 229 times
        dab_monobit2|  12|  65000000|       1|0.88431675|  PASSED
```
