# Stm32 (F0) avans lib

Een library voor de system workbench sfotware in combinatie met een stm32f091RC micro controller. deze library defineerd alle benodigde Registers en heeft wrapper functies voor bepaalde peripherals.

## content

- ### commen.h
    
    in dit bestand staan standaard includes, standaard datatypes & bit macro's

- ### registers/*
    
    in de register folder zijn de volgende registers gedefineerd.

    - adc.h         
    **alle registers die met de analog to digital converter te maken hebben**
    - exti.h         
    **alle registers die met extended interrupt controller te maken hebben**
    - gpio.h         
    **alle registers die met de gpio te maken hebben**
    - nvic.h         
    **alle registers die met de nested vector interrupt controller te maken hebben**
    - rcc.h         
    **alle registers die met de clock controller te maken hebben**
    - reg.h         
    **macros voor het defineren van een register**
    - syscfg.h         
    **alle registers die met de system config (exti) te maken hebben**
    - systick.h         
    **alle registers die met de system clock te maken hebben**
    - timer.h         
    **alle registers die met de timers te maken hebben**

- ### gpio/gpio.h

    hier in staan functies voor het aansturen en instellen van de gpio's.
    de functies kunnen meerdere io pinnen teglijk aanpassen door middel van de | (OR) operator te gebruiken.

    ```c
        gpio_set_mode(GPIO_PORT_B, GPIO_PIN_3, GPIO_MODE_OUTPUT); //maar 1 pin op output zetten
        gpio_set_mode(GPIO_PORT_B, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6, GPIO_MODE_OUTPUT); //meerdere pinnen tegelijk op output zetten
    ```

    beschikbare functies:

    ```c
        void gpio_set_mode(register_t port, uint16_t pins, gpio_modes_t mode);
        void gpio_set_input_settings(register_t port, uint16_t pins, gpio_input_type_t type);
        void gpio_set_output_settings(register_t port, uint16_t pins, gpio_output_type_t type, gpio_output_speed_t speed);
        void gpio_set_alternate_function(register_t port, uint16_t pins, gpio_alternate_function_t function);
        uint16_t gpio_read(register_t port, uint16_t pins);
        void gpio_write(register_t port, uint16_t pins, bool value);
        void gpio_set(register_t port, uint16_t pins);
        void gpio_reset(register_t port, uint16_t pins);
        void gpio_toggle(register_t port, uint16_t pins);
    ```

    beschikbare enums / constanten:

    Poorten selectie:
    ```c
        GPIO_PORT_A
        GPIO_PORT_B
        GPIO_PORT_C
        GPIO_PORT_D
        GPIO_PORT_E
        GPIO_PORT_F
    ```

    Pins selectie:
    ```c
        GPIO_PIN_0
        GPIO_PIN_1
        GPIO_PIN_2
        GPIO_PIN_3
        GPIO_PIN_4
        GPIO_PIN_5
        GPIO_PIN_6
        GPIO_PIN_7
        GPIO_PIN_8
        GPIO_PIN_9
        GPIO_PIN_10
        GPIO_PIN_11
        GPIO_PIN_12
        GPIO_PIN_13
        GPIO_PIN_14
        GPIO_PIN_15
    ```

    Mode selectie:
    ```c
        GPIO_MODE_INPUT
        GPIO_MODE_OUTPUT
        GPIO_MODE_ALTERNATE_FUNCTION
        GPIO_MODE_ANALOG
    ```

    Output type selectie:
    ```c
        GPIO_OUTPUT_TYPE_PUSH_PULL
        GPIO_OUTPUT_TYPE_OPEN_DRAIN
        GPIO_OUTPUT_TYPE_DEFAULT
    ```

    Output speed selectie:
    ```c
        GPIO_OUTPUT_SPEED_LOW
        GPIO_OUTPUT_SPEED_MEDIUM
        GPIO_OUTPUT_SPEED_HIGH
        GPIO_OUTPUT_SPEED_DEFAULT
    ```

    Input type selectie:
    ```c
        GPIO_INPUT_TYPE_NORMAL
        GPIO_INPUT_TYPE_PULLUP
        GPIO_INPUT_TYPE_PULLDOWN
    ```

    Alternate functie type selectie:
    ```c
        GPIO_AF0
        GPIO_AF1
        GPIO_AF2
        GPIO_AF3
        GPIO_AF4
        GPIO_AF5
        GPIO_AF6
        GPIO_AF7
    ```