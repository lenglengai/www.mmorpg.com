
namespace std {
	
	DbStatement::DbStatement(MYSQL_STMT * nHandle)
		: mHandle (nHandle)
	{
		int paramCount_ = mysql_stmt_param_count(nHandle);
		mParamBind = new MYSQL_BIND[paramCount_];
		memset(mParamBind, 0, sizeof(MYSQL_BIND) * paramCount_);
		
		my_bool bool_tmp = 1;
		mysql_stmt_attr_set(stmt, STMT_ATTR_UPDATE_MAX_LENGTH, &bool_tmp);
	}
	
	DbStatement::~DbStatement()
	{
	}
	
}
