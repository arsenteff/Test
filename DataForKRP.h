#pragma once

#include <stdint.h>

//! Структура для передачи данных от БПА для КРП
//! Структура для передачи данных от БПА для КРП
//! Структура для передачи данных от БПА для КРП
struct DataForKRP
{
    //! Режим работы БПН, 0x01 – Режим 1, 0x02 – Режим 2
	unsigned 	Mode : 2;
    //! Номер АРС, с которой работаем. Актуально только в Режиме 2.
	uint16_t 	ARSNumber;
    //! Частота в кГц, которую пеленгуем. Актуально только в Режиме 1.
    /**
     * 0x00 – при работе в Режиме 2.
     * 0x0001BDF6  – 114.166 МГц.
     * 0x0001BE9D – 114.333 МГц.
     * 0x0001BF97 – 114.583 МГц.
     * 0x0001DA9C – 121.5 МГц.
     * 0x0003B538 – 243.0 МГц.
     */
	uint32_t 	Frequency;
    //! КУР на радиостанцию в градусах. отрицательный КУР - КУР не определен.
	float 		KUR;
    //! Интенсивность сигнала от 0% до 100%. Актуально только в Режиме 1. 0x00 – 0%. 0x64 – 100%.
	uint8_t	SignalStrength;
    //! Последний результат контроля.
    /**
     * Перечень битов, 1–исправен, 0–неисправен.
     * 0 зарезервировано
     * 1 Результат контроля ячейки ОВЧ-Н
     * 2 Результат контроля ячейки ПРП-Н
     * 3 Результат контроля ячейки ПП-Н
     * 4 Результат контроля антенной системы
     * 5 зарезервировано
     * 7 Результат контроля ИП
     * 8 Отказ первого канала Arinc КРП - Отсутствует связь в течении 500 мс
     * 9 Отказ второго канала Arinc КРП- Отсутствует связь в течении 500 мс
     * 10 Отсутствует связь с ППА-С/В в течении 500 мс
     */
	uint16_t	ControlResult;
    //! Признак достоверности координат, полученных от АРС. 0x00 – координаты недостоверны. 0x01 – координаты достоверны.
	unsigned	CoordinateSymptom : 1;
    //! Широта в градусах, полученная от АРС
	float		ARSLatitude;
    //! Долгота в градусах, полученная от АРС.
	float		ARSLongitude;
    //! Геодезическая широта МП, градус
	double		Latitude;
    //! Геодезическая долгота МП, градус
	double		Longitude;
    //! Высота объекта над общеземным эллипсоидом, м
	float 		Altitude;
    //! Северная составляющая путевой скорости, км/ч
	float 		SpeedNorth;
    //! Восточная составляющая путевой скорости, км/ч
	float 		SpeedEastern;
    //! Вертикальная скорости, км/ч
	float 		SpeedVertical;
    //! Оцифровка меток времени "1с" (время московское «зимнее» или среднее Гринвичское)
    /**
     * 12 – 17 Час, 0…23
     * 6 – 11 Мин, 0…59
     * 0  – 5 Сек, 0…59
     */
	unsigned	Time	: 18;
    //! Время текущего обновления параметров относительно МВ “1 c” (последовательные приращения тактов 100 мс к секунде МВ)
    /**
     * Диапазон изменения параметра 1,0 с ЦМР=0,95мкс
     */
	unsigned	TimeLabel	: 21;
    //! Дата
    /**
     * 9 - 15 Год, 0…99
     * 5 – 8 Месяц, 1…12
     * 0 – 4 День, 1…31
     */
	uint16_t	Date;
    //! Расчетная ошибка определения координат (GDOP) м, ЦМР = 1 м
	unsigned	GDOP	: 15;
    //! "Признаки" (СП СРНС).
    /**
     * Разряд 0. Запрос "начальных" данных. "1" – запрос "начальных" данных, "0" – отсутствие запроса или НД получены
     * Разряды 1 - 2. Тип рабочей СРНС (с учетом работы в кодах точности СТ, ВТ, С/А):
     * "00" – не используется
     * "01" – работа только по ГЛОНАСС
     * "10" – работа только по GPS
     * "11" – работа по ГЛОНАСС + GPS
     * Разряд 3. Режим точности ГЛОНАСС (СТ, ВТ):
     * "1" - работа по ГЛОНАСС в коде ВТ
     * "0" - работа по ГЛОНАСС в коде СТ
     * Разряд 4. Отсутствует альманах по GPS
     * "1" – альманах отсутствует
     * "0" – есть альманах
     * Разряд 5. Отсутствует альманах по ГЛОНАСС
     * "1" – альманах отсутствует,
     * "0" – есть альманах
     * Разряды 6-7. Режим работы:
     * "00" – запрещенная комбинация
     * "10" – РАБОТА
     * "01" – КОНТРОЛЬ ПО КОМАНДЕ
     * "11" - режим «Имитация навигации»
     * Разряд 8. Подрежимы «Синхронизация» (поиск сигналов) или «Навигация»:
     * "1" – «Синхронизация»
     * "0" – «Навигация»
     * Разряд 9. Признак выдаваемого времени (Гринвичского или московского):
     * "1" – выдача ТГР,
     * "0" – выдача ТМСК
     * Разряд 10. Признак выдачи обновленных навигационно-временных параметров
     * "1" – выдаваемые данные обновлены
     * "0" – выдача "устаревших" данных
     * Разряд 11. Признак частотного диапазона L2 ГЛОНАСС
     * "1" – есть работа в диапазона L2 ГЛОНАСС
     * "0" - нет работы в диапазона L2 ГЛОНАСС
     * Разряд 12. Дифференциальный режим измерений
     * "0" – нет измерений в дифрежиме
     * "1" – есть работа в дифрежиме
     * Разряд 13. Действие функции RAIM
     * "0" – функция RAIM действует
     * "1" – функция RAIM невозможна
     * Разряд 14. Отказ изделия (в целом)
     * "1" – отказ,
     * "0" – исправность
     * Разряд 15. Подавление помех:
     * "0" – нет помех
     * "1" – есть помехи
     * Разряды 16 - 17.  Выбор системы координат:
     * "00" – НП на эллипсоиде СК-42.
     * "01" – НП на эллипсоиде WGS-84
     * "10" – НП на эллипсоиде ПЗ-90
     * "11" – НП на эллипсоиде СГС-95 (СГС-85)
     * Разряд 18. Признак частотного диапазона L2 GPS     
     * "1" – есть работа в диапазона L2 GPS
     * "0" - нет работы в диапазона L2 GPS
     * Разряд 19. Признак приема данных от БИНС     
     * "1" – нет достоверных данных от БИНС,
     * "0" – наличие достоверных данных от БИНС
     * Разряд 20. Начальные данные от БЦВМ отсутствуют     
     * "1" – НД отсутствуют,
     * "0" – НД приняты
     * Признак технологический, в алгоритме БЦВМ ИУС не используется
     */
	unsigned 	SRNSState	: 21;
    //! Технологические данные ППА‑С/В
    /**
     * 17 - 18 - тип СРНС: 00 – GPS, 01 – ГЛОНАСС, 10 - GALILEO
     * 11-16 -номер рабочего НС. Диапазон изменения параметра 1-32
     * 4 - 10 -Резерв
     * 0-3 -количество рабочих НС GPS. Диапазон изменения параметра 0 - 15
     */
	unsigned 	TechnoSRNS	: 19;
    //! Технологические данные ППА‑С/В
    /**
     * 16 - 21 - количество рабочих НС ГЛОНАСС; Диапазон изменения параметра 0 - 15
     * 11 - 15 - отношение сигнал/шум (усл. ед); Диапазон изменения параметра 0 - 25,6 ЦСР = 12,8
     * 7 - 10 -количество рабочих НС GALILEO; Диапазон изменения параметра 0 - 15
     * 1 - 6 - номер приемного канала; Диапазон: 1 - 48
     * 0 - НС принят в решение навигационной задачи; Диапазон: 0 или 1
     */
	unsigned	TechnoSputnic	: 22;
    //! Азимут и угол возвышения НС, градус
    /**
     * 7 - 15 А_СРНС; Диапазон изменения параметра 0 – 360, ЦСР = 180
     * 0 - 6 - Е_СРНС; Диапазон изменения параметра 0 – 90; ЦСР = 45???
     */
	uint16_t	TechnoAzimuth;
    //! Признак получены новые координаты АРС, 0 – нет новых данных, 1 – новые данные
	unsigned  	ARSNewCoordinates : 1;
    //! Отправка sms. 0 – sms отсутствует, 1– отправка sms
	unsigned    sms_valid : 1;
    //! Содержание sms
	uint64_t    sms;
    //! Состояние БПА (имитация матрицы по ARINC 429)
    /**
     * 00 – информация достоверна
     * 01 – режим контроль.
     * 10 – нет вычисленных данных
     * 11 – отказ БПА
     */
	unsigned	State : 2;
    //! Контрольная сумма, считается по crc32
	uint32_t	Checksum;
};
