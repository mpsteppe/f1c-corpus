unsigned __int16 __thiscall Concurrency::details::HardwareAffinity::GetGroup(
        Concurrency::details::HardwareAffinity *this)
{
  return *((_WORD *)this + 2);
}
