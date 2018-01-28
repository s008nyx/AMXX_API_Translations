#if defined _reapi_rechecker_included
	#endinput
#endif
#define _reapi_rechecker_included

enum ResourceType
{
	RES_TYPE_NONE = 0,
	RES_TYPE_EXISTS,    // сравнение с указанным значением хэша
	RES_TYPE_MISSING,   // проверить отсутствие файла на клиенте
	RES_TYPE_IGNORE,    // игнорировать указанное значение хэша
	RES_TYPE_HASH_ANY,  // любой файл с любым значением хэша
};

enum ReCheckerFunc
{
	/*
	* Description:   -
	* Params:        (const client, const filename[], const cmd[], const ResourceType:type, const responseHash, bool:isBreak)
	*/
	RC_FileConsistencyProcess = BEGIN_FUNC_REGION(rechecker),

	/*
	* Description:   -
	* Params:        (const client)
	*/
	RC_FileConsistencyFinal,

	/*
	* Description:   -
	* Params:        (const client, const filename[], const cmd[], const responseHash)
	*/
	RC_CmdExec,

	// [...]
};

/*
* Отправить запрос файла на клиенте, чтобы получить хэш
*
* @param file           Файл (может содержать относительный путь к файлу)
* @param function       Форвард, который вызывается
* @param type           Тип запроса может быть только RES_TYPE_EXISTS, RES_TYPE_MISSING или RES_TYPE_HASH_ANY
* @param hash           Хэш файла для запроса.
*
* @return               Возвращает хэндл хука. Используйте UnRegisterQueryFile для удаления форварда
*/
native QueryFileHook:RegisterQueryFile(const file[], const function[], const ResourceType:type, const hash = -1);

/*
* Удаление регистрации форварда.
* Используйте возвращаемое значение RegisterQueryFile в качестве параметра здесь!
*
* @param hook           Хук для удаления
*
* @return               Возвращает true, если хук успешно удален, иначе false
*/
native bool:UnRegisterQueryFile(QueryFileHook:hook);
