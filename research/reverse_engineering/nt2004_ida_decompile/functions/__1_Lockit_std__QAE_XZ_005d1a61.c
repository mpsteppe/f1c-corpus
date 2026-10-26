void __thiscall std::_Lockit::~_Lockit(std::_Lockit *this)
{
  if ( Target == 2 )
    LeaveCriticalSection(&CriticalSection);
}
