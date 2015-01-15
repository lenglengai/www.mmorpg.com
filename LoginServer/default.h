#pragma once

namespace std {

	namespace default_namespace {

		template<typename __t>
		struct Default
		{
			__t operator () () const
			{
				return 0;
			}
		};

		template<>
		struct Default<bool>
		{
			bool operator () () const
			{
				return false;
			}
		};

		template<>
		struct Default<float>
		{
			float operator () () const
			{
				return 0.f;
			}
		};

		template<>
		struct Default<double>
		{
			double operator () () const
			{
				return 0.;
			}
		};

		template<>
		struct Default<const char *>
		{
			const char * operator () ()const
			{
				return "";
			}
		};
		
	}

	template<typename __t>
	__t __default()
	{
		return default_namespace::Default<__t>()();
	}
	
	extern const string& __defaultstr();
	
	template<typename __t>
	shared_ptr<__t>& __defaultptr()
	{
		static shared_ptr<__t> result_;
		return result_;
	}

}
