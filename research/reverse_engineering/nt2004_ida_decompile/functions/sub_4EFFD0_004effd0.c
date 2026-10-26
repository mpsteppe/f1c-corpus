int __thiscall sub_4EFFD0(_BYTE *this)
{
  char v3; // [esp+0h] [ebp-4h]

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_19, 915) )
    sub_500FE0((int)&unk_7D7920, aEnteredSoundRe, v3);
  sub_4EFA70(this);
  Concurrency::details::_NonReentrantLock::_Release((Concurrency::details::_NonReentrantLock *)&unk_7D6BA0);
  return sub_419110(byte_6292D0);
}
