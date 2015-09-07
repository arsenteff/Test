#pragma once

#include <stdint.h>

//! Структура для передачи данных от КРП для БПА
struct DataForBPA
{
    //! Режим работы БПН
    /**
     * 0x00 – Режим функционального контроля
     * 0x01 – Режим 1.
     * 0x02 – Режим 2.
     * 0x03 – Режим диагностического контроля
     */
	unsigned Mode : 2;
    //! Повторный запрос АРС. 0 – нет запроса, 1 – есть запрос.
	unsigned ARSQuery : 1;
    //! Номер АРС, с которой работаем. Актуально только в Режиме 2.
	uint16_t NumberARS;
    //! Частота в кГц, которую пеленгуем. Актуально только в Режиме 1.
    /**
     * 0x00 – при работе в Режиме 2.
     * 0x0001BDF6  – 114.166 кГц.
     * 0x0001BE9D – 114.333 кГц.
     * 0x0001BF97 – 114.583 кГц.
     * 0x0001DA9C – 121.5 кГц.
     * 0x0003B538 – 243.0 кГц.
     */
	uint32_t Frequency;
    //! Отправка sms. 0 – sms отсутствует, 1– отправка sms
	unsigned    sms_valid : 1;
    //! Содержание sms
	uint64_t    sms;
    //! Состояние изделия КРП (имитация состояния матрицы по ARINC 429)
    /**
     * "00" – информация достоверна
     * "01" – режим контроль.
     * "10" –данные не готовы
     * "11" – отказ в КРП
     */
	unsigned State : 2;
    //! Контрольная сумма crc32 
	uint32_t	Checksum;
};