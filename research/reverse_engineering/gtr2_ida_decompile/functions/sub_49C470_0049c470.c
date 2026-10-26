int __thiscall sub_49C470(_DWORD **this)
{
  int v1; // eax
  const char *v2; // eax
  int v4; // [esp+10h] [ebp-220h]
  _BYTE v5[528]; // [esp+14h] [ebp-21Ch] BYREF
  int v6; // [esp+22Ch] [ebp-4h]

  v1 = (*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 19);
  if ( v1 )
  {
    if ( *(int *)(v1 + 600) < 0 )
    {
      v2 = (const char *)sub_4CE1C0(v1);
      if ( v2 )
      {
        atol(v2);
        sub_4744D0(v5);
        v6 = 0;
        if ( (unsigned __int8)sub_47A1A0() )
          sub_474860(&dword_B6CBA8, v4, 0);
        v6 = -1;
        nullsub_7(v5);
      }
    }
  }
  return 0;
}
