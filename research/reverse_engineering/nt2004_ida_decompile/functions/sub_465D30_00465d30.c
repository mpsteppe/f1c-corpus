int __thiscall sub_465D30(void *this)
{
  _DWORD v3[2]; // [esp+4h] [ebp-30h] BYREF
  __int16 v4; // [esp+Ch] [ebp-28h]
  HINSTANCE v5; // [esp+10h] [ebp-24h]
  char Buffer[32]; // [esp+14h] [ebp-20h] BYREF

  sub_56A120(v3);
  v3[1] = *(_DWORD *)this + 6712;
  v3[0] = 0;
  v5 = hinst;
  v4 = word_7699D8;
  sprintf(Buffer, "%s %.3f", aNascarThunderT, 1.001999974250793);
  if ( (unsigned __int8)sub_56A820(v3, *(_DWORD *)this + 6708) )
  {
    *(_DWORD *)(*(_DWORD *)this + 440) = 1;
    *(_DWORD *)(*(_DWORD *)this + 6716) = *(_DWORD *)this;
    *(_DWORD *)(*(_DWORD *)this + 6936) = sub_56A5B0(*(_DWORD *)(*(_DWORD *)this + 6708));
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)this + 440) = 0;
  }
  return sub_45E860((_DWORD *)(*(_DWORD *)this + 30136));
}
