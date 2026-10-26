int __thiscall sub_406640(_DWORD *this, int a2)
{
  int result; // eax

  result = this[3];
  if ( result == a2 )
    return MutexLockWithTimeout(1);
  return result;
}

