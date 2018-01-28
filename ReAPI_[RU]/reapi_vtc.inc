#if defined _reapi_vtc_included
	#endinput
#endif
#define _reapi_vtc_included

/*
* Проверяет, разговаривает ли игрок в данный момент-
*
* @param index      Индекс игрока
*
* @return           true если игрок говорит, в противном случае false
*/
native bool:VTC_IsClientSpeaking(const index);

/*
* Блокирует микрофон игрока.
*
* @param index      Индекс игрока
*
* @noreturn
*/
native VTC_MuteClient(const index);

/*
* Снимает блокировку с микрофона игрока.
*
* @param index      Индекс игрока
*
* @noreturn
*/
native VTC_UnmuteClient(const index);

/*
* Проверяет, заблокирован ли микрофон у игрока в данный момент
*
* @param index      Индекс игрока
*
* @return           true если микрофон заблокирован, в противном случае false
*/
native bool:VTC_IsClientMuted(const index);

/*
* Воспроизведение аудио файла через голосовой канал.
*
* @param receiver       Индекс получателя
* @param soundFilePath  Путь до аудио файла
*
* @note Пример использования:
*       VTC_PlaySound(id, "sound/ambience/Opera.wav");
*
* @noreturn
*/
native VTC_PlaySound(const receiver, const soundFilePath[]);

/*
* Вызывается, когда игрок начал говорить.
*
* @param index      Индекс игрока
*
* @noreturn
*/
forward VTC_OnClientStartSpeak(const index);

/*
* Вызывается, когда игрок закончил говорить.
*
* @param index      Индекс игрока
*
* @noreturn
*/
forward VTC_OnClientStopSpeak(const index);
