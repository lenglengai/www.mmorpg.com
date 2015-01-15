#pragma once

namespace std {
	
	class __funapi IDoing : public IService
	{
	public:
		virtual__i32 getDoingType() const = 0;
	};
	
}
