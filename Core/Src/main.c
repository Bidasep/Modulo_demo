/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan;

/* USER CODE BEGIN PV */
/*DEFINIÇAO DE VARIAVES */

	uint8_t estadoRele1 = 0;
	uint8_t estadoRele2 = 0;
	uint8_t estadoRele3 = 0;
	uint8_t estadoRele4 = 0;
	uint8_t eventoBotao = 0;
	uint8_t buzzerLigado = 0;
	uint32_t tempoInicioBuzzer = 0;

	/*TEMPORIZADORES DOS RELES PARA DESLIGAR AUTMÁTICO*/
	uint32_t tempoInicioRele1 = 0;
	uint32_t tempoInicioRele2 = 0;
	uint32_t tempoInicioRele3 = 0;
	uint32_t tempoInicioRele4 = 0;

	/* Estados usados no debounce */
	GPIO_PinState ultimaLeituraBotao1 = GPIO_PIN_SET;
	GPIO_PinState estadoEstavelBotao1 = GPIO_PIN_SET;

	GPIO_PinState ultimaLeituraBotao2 = GPIO_PIN_SET;
	GPIO_PinState estadoEstavelBotao2 = GPIO_PIN_SET;

	GPIO_PinState ultimaLeituraBotao3 = GPIO_PIN_SET;
	GPIO_PinState estadoEstavelBotao3 = GPIO_PIN_SET;

	GPIO_PinState ultimaLeituraBotao4 = GPIO_PIN_SET;
	GPIO_PinState estadoEstavelBotao4 = GPIO_PIN_SET;

	/* Momento em que a leitura do botão mudou */
	uint32_t tempoDebounceBotao1 = 0;
	uint32_t tempoDebounceBotao2 = 0;
	uint32_t tempoDebounceBotao3 = 0;
	uint32_t tempoDebounceBotao4 = 0;
	uint32_t tempoLedStatus = 0;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN_Init(void);
/* USER CODE BEGIN PFP */

/*FUNCOES */

void ControlarCanal(
    GPIO_TypeDef *botaoPort,
    uint16_t botaoPin,
    GPIO_TypeDef *relePort,
    uint16_t relePin,
    uint8_t *estadoRele,
    GPIO_PinState *ultimaLeitura,
    GPIO_PinState *estadoEstavel,
    uint32_t *tempoDebounce,
	uint32_t *tempoInicioRele
);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN_Init();
  /* USER CODE BEGIN 2 */
  /*DEFINE AS INICIALIZAÇÕES DOS GPIOS*/


  /*DEFINE O BUZZER COMO LOW*/
  HAL_GPIO_WritePin(BUZZER_GPIO_Port,BUZZER_Pin,GPIO_PIN_RESET);

  /*LED DE ENERGIA*/
  HAL_GPIO_WritePin(LED_POWER_GPIO_Port,LED_POWER_Pin,GPIO_PIN_RESET);

  /*STATUS */
  HAL_GPIO_WritePin(LED_STATUS_GPIO_Port,LED_STATUS_Pin,GPIO_PIN_SET);
  /*LED EXTERNO*/
  HAL_GPIO_WritePin(LED_STATUS_EXTERNO_GPIO_Port,LED_STATUS_EXTERNO_Pin,GPIO_PIN_SET);


  /*FORÇA O  SINAL_1 COMEÇAR EM ZERO*/
  HAL_GPIO_WritePin(SINAL_1_GPIO_Port,SINAL_1_Pin,GPIO_PIN_RESET);
  /*FORÇA O  SINAL_2 COMEÇAR EM ZERO*/
  HAL_GPIO_WritePin(SINAL_2_GPIO_Port,SINAL_2_Pin,GPIO_PIN_RESET);
  /*FORÇA O  SINAL_3 COMEÇAR EM ZERO*/
  HAL_GPIO_WritePin( SINAL_3_GPIO_Port,SINAL_3_Pin,GPIO_PIN_RESET);
  /*FORÇA O  SINAL_4 COMEÇAR EM ZERO*/
  HAL_GPIO_WritePin(SINAL_4_GPIO_Port,SINAL_4_Pin,GPIO_PIN_RESET);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	      ControlarCanal(
	          BOTAO_1_GPIO_Port,
	          BOTAO_1_Pin,
	          SINAL_1_GPIO_Port,
	          SINAL_1_Pin,
	          &estadoRele1,
	          &ultimaLeituraBotao1,
	          &estadoEstavelBotao1,
	          &tempoDebounceBotao1,
			  &tempoInicioRele1
	      );

	      ControlarCanal(
	          BOTAO_2_GPIO_Port,
	          BOTAO_2_Pin,
	          SINAL_2_GPIO_Port,
	          SINAL_2_Pin,
	          &estadoRele2,
	          &ultimaLeituraBotao2,
	          &estadoEstavelBotao2,
	          &tempoDebounceBotao2,
			  &tempoInicioRele2
	      );

	      ControlarCanal(
	          BOTAO_3_GPIO_Port,
	          BOTAO_3_Pin,
	          SINAL_3_GPIO_Port,
	          SINAL_3_Pin,
	          &estadoRele3,
	          &ultimaLeituraBotao3,
	          &estadoEstavelBotao3,
	          &tempoDebounceBotao3,
			  &tempoInicioRele3
	      );

	      ControlarCanal(
	          BOTAO_4_GPIO_Port,
	          BOTAO_4_Pin,
	          SINAL_4_GPIO_Port,
	          SINAL_4_Pin,
	          &estadoRele4,
	          &ultimaLeituraBotao4,
	          &estadoEstavelBotao4,
	          &tempoDebounceBotao4,
			  &tempoInicioRele1
	      );

	      /* Pisca o LED de funcionamento a cada 500 ms */
	          if ((HAL_GetTick() - tempoLedStatus) >= 500)
	          {
	              tempoLedStatus = HAL_GetTick();

	              HAL_GPIO_TogglePin(
	                  LED_STATUS_GPIO_Port,
	                  LED_STATUS_Pin
	              );

	              /* LED externo de funcionamento */
	              HAL_GPIO_TogglePin(
	                  LED_STATUS_EXTERNO_GPIO_Port,
	                  LED_STATUS_EXTERNO_Pin
	              );
	          }


	         /*LOGICA DO BUZZER 3S*/
	          if (eventoBotao == 1)
	          {
	              HAL_GPIO_WritePin(
	                  BUZZER_GPIO_Port,
	                  BUZZER_Pin,
	                  GPIO_PIN_SET
	              );

	              buzzerLigado = 1;
	              tempoInicioBuzzer = HAL_GetTick();

	              eventoBotao = 0;
	          }

	          if (
	              buzzerLigado == 1 &&
	              (HAL_GetTick() - tempoInicioBuzzer) >= 3000
	          )
	          {
	              HAL_GPIO_WritePin(
	                  BUZZER_GPIO_Port,
	                  BUZZER_Pin,
	                  GPIO_PIN_RESET
	              );

	              buzzerLigado = 0;
	          }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	      /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 4;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_15TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = ENABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = ENABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */

  /* USER CODE END CAN_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_STATUS_Pin|LED_POWER_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, BUZZER_Pin|SINAL_2_Pin|SINAL_3_Pin|SINAL_4_Pin
                          |LED_CAN_Pin|LED_STATUS_EXTERNO_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SINAL_1_GPIO_Port, SINAL_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_STATUS_Pin LED_POWER_Pin */
  GPIO_InitStruct.Pin = LED_STATUS_Pin|LED_POWER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : BOTAO_1_Pin BOTAO_2_Pin BOTAO_3_Pin BOTAO_4_Pin */
  GPIO_InitStruct.Pin = BOTAO_1_Pin|BOTAO_2_Pin|BOTAO_3_Pin|BOTAO_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : BUZZER_Pin SINAL_2_Pin SINAL_3_Pin SINAL_4_Pin
                           LED_CAN_Pin LED_STATUS_EXTERNO_Pin */
  GPIO_InitStruct.Pin = BUZZER_Pin|SINAL_2_Pin|SINAL_3_Pin|SINAL_4_Pin
                          |LED_CAN_Pin|LED_STATUS_EXTERNO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : SINAL_1_Pin */
  GPIO_InitStruct.Pin = SINAL_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SINAL_1_GPIO_Port, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE BEGIN 4 */

/*FUNÇÃO PARA TRATAMENTO DOS BOTÕES*/

void ControlarCanal(
    GPIO_TypeDef *botaoPort,
    uint16_t botaoPin,
    GPIO_TypeDef *relePort,
    uint16_t relePin,
    uint8_t *estadoRele,
    GPIO_PinState *ultimaLeitura,
    GPIO_PinState *estadoEstavel,
    uint32_t *tempoDebounce,
	uint32_t *tempoInicioRele
)
{
    GPIO_PinState leituraAtual =
        HAL_GPIO_ReadPin(botaoPort, botaoPin);



    /*
     * Se a leitura mudou, reinicia o tempo
     * necessário para o debounce.
     */
    if (leituraAtual != *ultimaLeitura)
    {
        *tempoDebounce = HAL_GetTick();
    }

    /*
     * Só aceita a mudança depois do tempo estabelecido configuradi inicial para 30ms ( >= 30)ms
     * sem alteração na leitura.
     */
    /* Para mudar o tempo modificar */
    if ((HAL_GetTick() - *tempoDebounce) >= 30)
    {
        if (leituraAtual != *estadoEstavel)
        {
            *estadoEstavel = leituraAtual;

            /*
             * o botão usa pull-up,
             * RESET representa botão pressionado.
             */
            if (*estadoEstavel == GPIO_PIN_RESET)
            {
                /* Alterna entre ligado e desligado */
                *estadoRele = !(*estadoRele);

                HAL_GPIO_WritePin(
                    relePort,
                    relePin,
                    *estadoRele
                        ? GPIO_PIN_SET
                        : GPIO_PIN_RESET
                );

                /*Se o novo estado for ligado, salva o instante e aciona o evento do buzzer.
                 */
                if (*estadoRele == 1)
                {
                    *tempoInicioRele = HAL_GetTick();
                    eventoBotao = 1;
                }
            }
        }
    }

    /* Guarda a leitura atual para a próximaexecução da função.*/
    /*Se o relé estiver ligado e completar 10 segundos, desliga automaticamente.*/

    /*MUDAR O TEMPO PARA DESLIGAR O RELE DAS SINALEIRAS ESTÁ COM 1 MINUT*/
    if (
        *estadoRele == 1 &&
        (HAL_GetTick() - *tempoInicioRele) >= 60000
    )
    {
        *estadoRele = 0;

        HAL_GPIO_WritePin(
            relePort,
            relePin,
            GPIO_PIN_RESET
        );
    }


    *ultimaLeitura = leituraAtual;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
