int __thiscall sub_4A2450(_DWORD *this)
{
  float *v2; // eax
  float *v3; // edi
  char Buffer[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v6; // [esp+45h] [ebp-3h]
  char v7; // [esp+47h] [ebp-1h]

  memset(Buffer, 0, sizeof(Buffer));
  v6 = 0;
  v7 = 0;
  v2 = (float *)(*(int (__thiscall **)(_DWORD *))(*this + 188))(this);
  v3 = v2;
  if ( v2 )
  {
    sprintf(Buffer, "%d%%", (unsigned int)(unsigned __int64)(*v2 * 100.0 + 0.5));
    if ( this[75] == 262 )
      sub_5400D0(*(_DWORD *)v3);
  }
  sub_615860(Buffer);
  return 0;
}
