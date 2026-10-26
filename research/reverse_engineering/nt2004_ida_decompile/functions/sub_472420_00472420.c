char __thiscall sub_472420(int this)
{
  const char *v2; // eax
  char Buffer[253]; // [esp+4h] [ebp-100h] BYREF
  __int16 v5; // [esp+101h] [ebp-3h]
  char v6; // [esp+103h] [ebp-1h]

  if ( dword_75CBA8 != 5 )
  {
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0xFCu);
    v5 = 0;
    v6 = 0;
    v2 = *(const char **)dword_62A0D0;
    if ( !*(_DWORD *)dword_62A0D0 )
      v2 = &byte_629120;
    sprintf(Buffer, "%s%s", v2, aTmptrackScn);
    *(_DWORD *)(this + 432) = dword_7D6B54;
    sub_471DA0(Buffer, 0, aTviewScn);
    sub_578600(Buffer);
    sub_46E7C0(this);
    if ( dword_7656E0 )
    {
      *(_DWORD *)(this + 280) = sub_597590(0);
      *(_DWORD *)(this + 268) = sub_597290(dword_7656E0);
    }
    remove(Buffer);
    sub_46F1B0((_BYTE *)this);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)this + 40))(this, 1);
    dword_600F40 = -1082130432;
  }
  return 0;
}
