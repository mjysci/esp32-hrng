# ESP32-C3 RNG Benchmark

## esp_fill_random

```sh
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |           filename             |rands/second|
 file_input_raw|                      rng-c3.bin|  8.93e+07  |
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.39433721|  PASSED  
      diehard_operm5|   0|   1000000|     100|0.94497216|  PASSED  
  diehard_rank_32x32|   0|     40000|     100|0.26581905|  PASSED  
# The file file_input_raw was rewound 1 times
    diehard_rank_6x8|   0|    100000|     100|0.71892228|  PASSED  
# The file file_input_raw was rewound 1 times
   diehard_bitstream|   0|   2097152|     100|0.96723520|  PASSED  
# The file file_input_raw was rewound 2 times
        diehard_opso|   0|   2097152|     100|0.81996034|  PASSED  
# The file file_input_raw was rewound 2 times
        diehard_oqso|   0|   2097152|     100|0.43413686|  PASSED  
# The file file_input_raw was rewound 2 times
         diehard_dna|   0|   2097152|     100|0.67944314|  PASSED  
# The file file_input_raw was rewound 2 times
diehard_count_1s_str|   0|    256000|     100|0.96322569|  PASSED  
# The file file_input_raw was rewound 3 times
diehard_count_1s_byt|   0|    256000|     100|0.66141269|  PASSED  
# The file file_input_raw was rewound 3 times
 diehard_parking_lot|   0|     12000|     100|0.90061093|  PASSED  
# The file file_input_raw was rewound 3 times
    diehard_2dsphere|   2|      8000|     100|0.76172848|  PASSED  
# The file file_input_raw was rewound 3 times
    diehard_3dsphere|   3|      4000|     100|0.42576336|  PASSED  
# The file file_input_raw was rewound 4 times
     diehard_squeeze|   0|    100000|     100|0.80251375|  PASSED  
# The file file_input_raw was rewound 4 times
        diehard_sums|   0|       100|     100|0.50477050|  PASSED  
# The file file_input_raw was rewound 4 times
        diehard_runs|   0|    100000|     100|0.78553785|  PASSED  
        diehard_runs|   0|    100000|     100|0.46762596|  PASSED  
# The file file_input_raw was rewound 4 times
       diehard_craps|   0|    200000|     100|0.57225133|  PASSED  
       diehard_craps|   0|    200000|     100|0.33451117|  PASSED  
# The file file_input_raw was rewound 12 times
 marsaglia_tsang_gcd|   0|  10000000|     100|0.37440689|  PASSED  
 marsaglia_tsang_gcd|   0|  10000000|     100|0.07592346|  PASSED  
# The file file_input_raw was rewound 12 times
         sts_monobit|   1|    100000|     100|0.00000000|  FAILED  
# The file file_input_raw was rewound 12 times
            sts_runs|   2|    100000|     100|0.05634618|  PASSED  
# The file file_input_raw was rewound 12 times
          sts_serial|   1|    100000|     100|0.00000170|   WEAK   
          sts_serial|   2|    100000|     100|0.00629595|  PASSED  
          sts_serial|   3|    100000|     100|0.00172974|   WEAK   
          sts_serial|   3|    100000|     100|0.03637348|  PASSED  
          sts_serial|   4|    100000|     100|0.61332231|  PASSED  
          sts_serial|   4|    100000|     100|0.05229103|  PASSED  
          sts_serial|   5|    100000|     100|0.44681868|  PASSED  
          sts_serial|   5|    100000|     100|0.69282014|  PASSED  
          sts_serial|   6|    100000|     100|0.27458396|  PASSED  
          sts_serial|   6|    100000|     100|0.51400796|  PASSED  
          sts_serial|   7|    100000|     100|0.68548717|  PASSED  
          sts_serial|   7|    100000|     100|0.70307387|  PASSED  
          sts_serial|   8|    100000|     100|0.39018263|  PASSED  
          sts_serial|   8|    100000|     100|0.51145772|  PASSED  
          sts_serial|   9|    100000|     100|0.11243588|  PASSED  
          sts_serial|   9|    100000|     100|0.09380908|  PASSED  
          sts_serial|  10|    100000|     100|0.28435322|  PASSED  
          sts_serial|  10|    100000|     100|0.32484343|  PASSED  
          sts_serial|  11|    100000|     100|0.23852184|  PASSED  
          sts_serial|  11|    100000|     100|0.92842810|  PASSED  
          sts_serial|  12|    100000|     100|0.06431654|  PASSED  
          sts_serial|  12|    100000|     100|0.41667536|  PASSED  
          sts_serial|  13|    100000|     100|0.04724636|  PASSED  
          sts_serial|  13|    100000|     100|0.53417901|  PASSED  
          sts_serial|  14|    100000|     100|0.02370558|  PASSED  
          sts_serial|  14|    100000|     100|0.45823905|  PASSED  
          sts_serial|  15|    100000|     100|0.09268650|  PASSED  
          sts_serial|  15|    100000|     100|0.96256242|  PASSED  
          sts_serial|  16|    100000|     100|0.10110034|  PASSED  
          sts_serial|  16|    100000|     100|0.62724505|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   1|    100000|     100|0.08595302|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   2|    100000|     100|0.01004829|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   3|    100000|     100|0.54707586|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   4|    100000|     100|0.16159619|  PASSED  
# The file file_input_raw was rewound 13 times
         rgb_bitdist|   5|    100000|     100|0.39979598|  PASSED  
# The file file_input_raw was rewound 13 times
         rgb_bitdist|   6|    100000|     100|0.56477465|  PASSED  
# The file file_input_raw was rewound 14 times
         rgb_bitdist|   7|    100000|     100|0.13505470|  PASSED  
# The file file_input_raw was rewound 14 times
         rgb_bitdist|   8|    100000|     100|0.65386214|  PASSED  
# The file file_input_raw was rewound 15 times
         rgb_bitdist|   9|    100000|     100|0.35612417|  PASSED  
# The file file_input_raw was rewound 16 times
         rgb_bitdist|  10|    100000|     100|0.76232463|  PASSED  
# The file file_input_raw was rewound 17 times
         rgb_bitdist|  11|    100000|     100|0.37654575|  PASSED  
# The file file_input_raw was rewound 18 times
         rgb_bitdist|  12|    100000|     100|0.98030356|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   2|     10000|    1000|0.50852065|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   3|     10000|    1000|0.38837898|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   4|     10000|    1000|0.09008473|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   5|     10000|    1000|0.25032273|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   2|    100000|     100|0.72913019|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   3|    100000|     100|0.99542855|   WEAK   
# The file file_input_raw was rewound 18 times
    rgb_permutations|   4|    100000|     100|0.90638502|  PASSED  
# The file file_input_raw was rewound 19 times
    rgb_permutations|   5|    100000|     100|0.33626069|  PASSED  
# The file file_input_raw was rewound 19 times
      rgb_lagged_sum|   0|   1000000|     100|0.03793181|  PASSED  
# The file file_input_raw was rewound 20 times
      rgb_lagged_sum|   1|   1000000|     100|0.16503233|  PASSED  
# The file file_input_raw was rewound 21 times
      rgb_lagged_sum|   2|   1000000|     100|0.02264313|  PASSED  
# The file file_input_raw was rewound 22 times
      rgb_lagged_sum|   3|   1000000|     100|0.00052125|   WEAK   
# The file file_input_raw was rewound 24 times
      rgb_lagged_sum|   4|   1000000|     100|0.24563259|  PASSED  
# The file file_input_raw was rewound 26 times
      rgb_lagged_sum|   5|   1000000|     100|0.01811931|  PASSED  
# The file file_input_raw was rewound 29 times
      rgb_lagged_sum|   6|   1000000|     100|0.05360549|  PASSED  
# The file file_input_raw was rewound 32 times
      rgb_lagged_sum|   7|   1000000|     100|0.00423641|   WEAK   
# The file file_input_raw was rewound 35 times
      rgb_lagged_sum|   8|   1000000|     100|0.15596423|  PASSED  
# The file file_input_raw was rewound 39 times
      rgb_lagged_sum|   9|   1000000|     100|0.01898154|  PASSED  
# The file file_input_raw was rewound 43 times
      rgb_lagged_sum|  10|   1000000|     100|0.00321784|   WEAK   
# The file file_input_raw was rewound 48 times
      rgb_lagged_sum|  11|   1000000|     100|0.02036918|  PASSED  
# The file file_input_raw was rewound 53 times
      rgb_lagged_sum|  12|   1000000|     100|0.00064557|   WEAK   
# The file file_input_raw was rewound 58 times
      rgb_lagged_sum|  13|   1000000|     100|0.38274414|  PASSED  
# The file file_input_raw was rewound 63 times
      rgb_lagged_sum|  14|   1000000|     100|0.00119172|   WEAK   
# The file file_input_raw was rewound 69 times
      rgb_lagged_sum|  15|   1000000|     100|0.00034908|   WEAK   
# The file file_input_raw was rewound 76 times
      rgb_lagged_sum|  16|   1000000|     100|0.05943908|  PASSED  
# The file file_input_raw was rewound 82 times
      rgb_lagged_sum|  17|   1000000|     100|0.04794050|  PASSED  
# The file file_input_raw was rewound 89 times
      rgb_lagged_sum|  18|   1000000|     100|0.07273561|  PASSED  
# The file file_input_raw was rewound 97 times
      rgb_lagged_sum|  19|   1000000|     100|0.00370082|   WEAK   
# The file file_input_raw was rewound 105 times
      rgb_lagged_sum|  20|   1000000|     100|0.46414865|  PASSED  
# The file file_input_raw was rewound 113 times
      rgb_lagged_sum|  21|   1000000|     100|0.11027967|  PASSED  
# The file file_input_raw was rewound 121 times
      rgb_lagged_sum|  22|   1000000|     100|0.02883355|  PASSED  
# The file file_input_raw was rewound 130 times
      rgb_lagged_sum|  23|   1000000|     100|0.00977293|  PASSED  
# The file file_input_raw was rewound 140 times
      rgb_lagged_sum|  24|   1000000|     100|0.00432637|   WEAK   
# The file file_input_raw was rewound 149 times
      rgb_lagged_sum|  25|   1000000|     100|0.17749130|  PASSED  
# The file file_input_raw was rewound 159 times
      rgb_lagged_sum|  26|   1000000|     100|0.00247160|   WEAK   
# The file file_input_raw was rewound 170 times
      rgb_lagged_sum|  27|   1000000|     100|0.00042340|   WEAK   
# The file file_input_raw was rewound 181 times
      rgb_lagged_sum|  28|   1000000|     100|0.04699140|  PASSED  
# The file file_input_raw was rewound 192 times
      rgb_lagged_sum|  29|   1000000|     100|0.03490410|  PASSED  
# The file file_input_raw was rewound 203 times
      rgb_lagged_sum|  30|   1000000|     100|0.02018763|  PASSED  
# The file file_input_raw was rewound 215 times
      rgb_lagged_sum|  31|   1000000|     100|0.00058731|   WEAK   
# The file file_input_raw was rewound 228 times
      rgb_lagged_sum|  32|   1000000|     100|0.02383249|  PASSED  
# The file file_input_raw was rewound 228 times
     rgb_kstest_test|   0|     10000|    1000|0.05011631|  PASSED  
# The file file_input_raw was rewound 228 times
     dab_bytedistrib|   0|  51200000|       1|0.00000000|  FAILED  
# The file file_input_raw was rewound 228 times
             dab_dct| 256|     50000|       1|0.47790303|  PASSED  
Preparing to run test 207.  ntuple = 0
# The file file_input_raw was rewound 229 times
        dab_filltree|  32|  15000000|       1|0.48253380|  PASSED  
        dab_filltree|  32|  15000000|       1|0.21589729|  PASSED  
Preparing to run test 208.  ntuple = 0
# The file file_input_raw was rewound 229 times
       dab_filltree2|   0|   5000000|       1|0.54359011|  PASSED  
       dab_filltree2|   1|   5000000|       1|0.01054316|  PASSED  
Preparing to run test 209.  ntuple = 0
# The file file_input_raw was rewound 229 times
        dab_monobit2|  12|  65000000|       1|1.00000000|  FAILED
```

## csprng_fill_random

```sh
#=============================================================================#
#            dieharder version 3.31.1 Copyright 2003 Robert G. Brown          #
#=============================================================================#
   rng_name    |           filename             |rands/second|
 file_input_raw|                   csprng-c3.bin|  9.26e+07  |
#=============================================================================#
        test_name   |ntup| tsamples |psamples|  p-value |Assessment
#=============================================================================#
   diehard_birthdays|   0|       100|     100|0.21534933|  PASSED  
      diehard_operm5|   0|   1000000|     100|0.68061801|  PASSED  
  diehard_rank_32x32|   0|     40000|     100|0.30665730|  PASSED  
# The file file_input_raw was rewound 1 times
    diehard_rank_6x8|   0|    100000|     100|0.44263558|  PASSED  
# The file file_input_raw was rewound 1 times
   diehard_bitstream|   0|   2097152|     100|0.08041771|  PASSED  
# The file file_input_raw was rewound 2 times
        diehard_opso|   0|   2097152|     100|0.81225527|  PASSED  
# The file file_input_raw was rewound 2 times
        diehard_oqso|   0|   2097152|     100|0.97976675|  PASSED  
# The file file_input_raw was rewound 2 times
         diehard_dna|   0|   2097152|     100|0.76616900|  PASSED  
# The file file_input_raw was rewound 2 times
diehard_count_1s_str|   0|    256000|     100|0.67865700|  PASSED  
# The file file_input_raw was rewound 3 times
diehard_count_1s_byt|   0|    256000|     100|0.93843428|  PASSED  
# The file file_input_raw was rewound 3 times
 diehard_parking_lot|   0|     12000|     100|0.22401317|  PASSED  
# The file file_input_raw was rewound 3 times
    diehard_2dsphere|   2|      8000|     100|0.61197206|  PASSED  
# The file file_input_raw was rewound 3 times
    diehard_3dsphere|   3|      4000|     100|0.66514760|  PASSED  
# The file file_input_raw was rewound 4 times
     diehard_squeeze|   0|    100000|     100|0.15966945|  PASSED  
# The file file_input_raw was rewound 4 times
        diehard_sums|   0|       100|     100|0.33372446|  PASSED  
# The file file_input_raw was rewound 4 times
        diehard_runs|   0|    100000|     100|0.56458792|  PASSED  
        diehard_runs|   0|    100000|     100|0.82489463|  PASSED  
# The file file_input_raw was rewound 4 times
       diehard_craps|   0|    200000|     100|0.57722781|  PASSED  
       diehard_craps|   0|    200000|     100|0.76792063|  PASSED  
# The file file_input_raw was rewound 12 times
 marsaglia_tsang_gcd|   0|  10000000|     100|0.00929318|  PASSED  
 marsaglia_tsang_gcd|   0|  10000000|     100|0.59632511|  PASSED  
# The file file_input_raw was rewound 12 times
         sts_monobit|   1|    100000|     100|0.00000000|  FAILED  
# The file file_input_raw was rewound 12 times
            sts_runs|   2|    100000|     100|0.17842313|  PASSED  
# The file file_input_raw was rewound 12 times
          sts_serial|   1|    100000|     100|0.00000000|  FAILED  
          sts_serial|   2|    100000|     100|0.00377820|   WEAK   
          sts_serial|   3|    100000|     100|0.06030920|  PASSED  
          sts_serial|   3|    100000|     100|0.99966125|   WEAK   
          sts_serial|   4|    100000|     100|0.57693945|  PASSED  
          sts_serial|   4|    100000|     100|0.75586783|  PASSED  
          sts_serial|   5|    100000|     100|0.20024616|  PASSED  
          sts_serial|   5|    100000|     100|0.73450045|  PASSED  
          sts_serial|   6|    100000|     100|0.87342722|  PASSED  
          sts_serial|   6|    100000|     100|0.12083134|  PASSED  
          sts_serial|   7|    100000|     100|0.39515173|  PASSED  
          sts_serial|   7|    100000|     100|0.60605563|  PASSED  
          sts_serial|   8|    100000|     100|0.64840197|  PASSED  
          sts_serial|   8|    100000|     100|0.20521124|  PASSED  
          sts_serial|   9|    100000|     100|0.26851959|  PASSED  
          sts_serial|   9|    100000|     100|0.99928993|   WEAK   
          sts_serial|  10|    100000|     100|0.74671922|  PASSED  
          sts_serial|  10|    100000|     100|0.50167229|  PASSED  
          sts_serial|  11|    100000|     100|0.42915989|  PASSED  
          sts_serial|  11|    100000|     100|0.30168113|  PASSED  
          sts_serial|  12|    100000|     100|0.84194038|  PASSED  
          sts_serial|  12|    100000|     100|0.02261517|  PASSED  
          sts_serial|  13|    100000|     100|0.53736311|  PASSED  
          sts_serial|  13|    100000|     100|0.64297256|  PASSED  
          sts_serial|  14|    100000|     100|0.89208341|  PASSED  
          sts_serial|  14|    100000|     100|0.80050898|  PASSED  
          sts_serial|  15|    100000|     100|0.77619144|  PASSED  
          sts_serial|  15|    100000|     100|0.36283484|  PASSED  
          sts_serial|  16|    100000|     100|0.91129699|  PASSED  
          sts_serial|  16|    100000|     100|0.55656110|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   1|    100000|     100|0.02315705|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   2|    100000|     100|0.12256638|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   3|    100000|     100|0.50637607|  PASSED  
# The file file_input_raw was rewound 12 times
         rgb_bitdist|   4|    100000|     100|0.45579714|  PASSED  
# The file file_input_raw was rewound 13 times
         rgb_bitdist|   5|    100000|     100|0.99285660|  PASSED  
# The file file_input_raw was rewound 13 times
         rgb_bitdist|   6|    100000|     100|0.61167731|  PASSED  
# The file file_input_raw was rewound 14 times
         rgb_bitdist|   7|    100000|     100|0.49521263|  PASSED  
# The file file_input_raw was rewound 14 times
         rgb_bitdist|   8|    100000|     100|0.50448605|  PASSED  
# The file file_input_raw was rewound 15 times
         rgb_bitdist|   9|    100000|     100|0.61959766|  PASSED  
# The file file_input_raw was rewound 16 times
         rgb_bitdist|  10|    100000|     100|0.87008260|  PASSED  
# The file file_input_raw was rewound 17 times
         rgb_bitdist|  11|    100000|     100|0.00923289|  PASSED  
# The file file_input_raw was rewound 18 times
         rgb_bitdist|  12|    100000|     100|0.90847633|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   2|     10000|    1000|0.19482173|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   3|     10000|    1000|0.31980660|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   4|     10000|    1000|0.47688707|  PASSED  
# The file file_input_raw was rewound 18 times
rgb_minimum_distance|   5|     10000|    1000|0.66404002|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   2|    100000|     100|0.77622141|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   3|    100000|     100|0.79447729|  PASSED  
# The file file_input_raw was rewound 18 times
    rgb_permutations|   4|    100000|     100|0.99441159|  PASSED  
# The file file_input_raw was rewound 19 times
    rgb_permutations|   5|    100000|     100|0.04300837|  PASSED  
# The file file_input_raw was rewound 19 times
      rgb_lagged_sum|   0|   1000000|     100|0.00033269|   WEAK   
# The file file_input_raw was rewound 20 times
      rgb_lagged_sum|   1|   1000000|     100|0.00205788|   WEAK   
# The file file_input_raw was rewound 21 times
      rgb_lagged_sum|   2|   1000000|     100|0.00769771|  PASSED  
# The file file_input_raw was rewound 22 times
      rgb_lagged_sum|   3|   1000000|     100|0.00140131|   WEAK   
# The file file_input_raw was rewound 24 times
      rgb_lagged_sum|   4|   1000000|     100|0.00198693|   WEAK   
# The file file_input_raw was rewound 26 times
      rgb_lagged_sum|   5|   1000000|     100|0.00279340|   WEAK   
# The file file_input_raw was rewound 29 times
      rgb_lagged_sum|   6|   1000000|     100|0.00912988|  PASSED  
# The file file_input_raw was rewound 32 times
      rgb_lagged_sum|   7|   1000000|     100|0.00271202|   WEAK   
# The file file_input_raw was rewound 35 times
      rgb_lagged_sum|   8|   1000000|     100|0.00832529|  PASSED  
# The file file_input_raw was rewound 39 times
      rgb_lagged_sum|   9|   1000000|     100|0.00004624|   WEAK   
# The file file_input_raw was rewound 43 times
      rgb_lagged_sum|  10|   1000000|     100|0.00008498|   WEAK   
# The file file_input_raw was rewound 48 times
      rgb_lagged_sum|  11|   1000000|     100|0.00001428|   WEAK   
# The file file_input_raw was rewound 53 times
      rgb_lagged_sum|  12|   1000000|     100|0.00111792|   WEAK   
# The file file_input_raw was rewound 58 times
      rgb_lagged_sum|  13|   1000000|     100|0.00028785|   WEAK   
# The file file_input_raw was rewound 63 times
      rgb_lagged_sum|  14|   1000000|     100|0.00175138|   WEAK   
# The file file_input_raw was rewound 69 times
      rgb_lagged_sum|  15|   1000000|     100|0.01433695|  PASSED  
# The file file_input_raw was rewound 76 times
      rgb_lagged_sum|  16|   1000000|     100|0.00183447|   WEAK   
# The file file_input_raw was rewound 82 times
      rgb_lagged_sum|  17|   1000000|     100|0.02066736|  PASSED  
# The file file_input_raw was rewound 89 times
      rgb_lagged_sum|  18|   1000000|     100|0.04565166|  PASSED  
# The file file_input_raw was rewound 97 times
      rgb_lagged_sum|  19|   1000000|     100|0.00091441|   WEAK   
# The file file_input_raw was rewound 105 times
      rgb_lagged_sum|  20|   1000000|     100|0.00273719|   WEAK   
# The file file_input_raw was rewound 113 times
      rgb_lagged_sum|  21|   1000000|     100|0.00022617|   WEAK   
# The file file_input_raw was rewound 121 times
      rgb_lagged_sum|  22|   1000000|     100|0.00000159|   WEAK   
# The file file_input_raw was rewound 130 times
      rgb_lagged_sum|  23|   1000000|     100|0.02083389|  PASSED  
# The file file_input_raw was rewound 140 times
      rgb_lagged_sum|  24|   1000000|     100|0.09657986|  PASSED  
# The file file_input_raw was rewound 149 times
      rgb_lagged_sum|  25|   1000000|     100|0.00037610|   WEAK   
# The file file_input_raw was rewound 159 times
      rgb_lagged_sum|  26|   1000000|     100|0.00007761|   WEAK   
# The file file_input_raw was rewound 170 times
      rgb_lagged_sum|  27|   1000000|     100|0.00001315|   WEAK   
# The file file_input_raw was rewound 181 times
      rgb_lagged_sum|  28|   1000000|     100|0.00002256|   WEAK   
# The file file_input_raw was rewound 192 times
      rgb_lagged_sum|  29|   1000000|     100|0.00174516|   WEAK   
# The file file_input_raw was rewound 203 times
      rgb_lagged_sum|  30|   1000000|     100|0.00000528|   WEAK   
# The file file_input_raw was rewound 215 times
      rgb_lagged_sum|  31|   1000000|     100|0.06460859|  PASSED  
# The file file_input_raw was rewound 228 times
      rgb_lagged_sum|  32|   1000000|     100|0.00084202|   WEAK   
# The file file_input_raw was rewound 228 times
     rgb_kstest_test|   0|     10000|    1000|0.20174668|  PASSED  
# The file file_input_raw was rewound 228 times
     dab_bytedistrib|   0|  51200000|       1|0.00000000|  FAILED  
# The file file_input_raw was rewound 228 times
             dab_dct| 256|     50000|       1|0.13257191|  PASSED  
Preparing to run test 207.  ntuple = 0
# The file file_input_raw was rewound 229 times
        dab_filltree|  32|  15000000|       1|0.95784696|  PASSED  
        dab_filltree|  32|  15000000|       1|0.19932460|  PASSED  
Preparing to run test 208.  ntuple = 0
# The file file_input_raw was rewound 229 times
       dab_filltree2|   0|   5000000|       1|0.88967197|  PASSED  
       dab_filltree2|   1|   5000000|       1|0.00897606|  PASSED  
Preparing to run test 209.  ntuple = 0
# The file file_input_raw was rewound 229 times
        dab_monobit2|  12|  65000000|       1|1.00000000|  FAILED
```
