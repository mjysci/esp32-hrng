idf_component_register(
    SRCS "rng_api_server.c"
    INCLUDE_DIRS "include"
    REQUIRES esp_http_server json csprng esp_driver_gpio
)