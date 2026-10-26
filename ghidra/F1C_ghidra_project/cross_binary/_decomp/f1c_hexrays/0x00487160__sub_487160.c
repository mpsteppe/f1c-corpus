// f1c  0x00487160  size=122
char __thiscall sub_487160(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // edx
  __int16 v7; // [esp+Ch] [ebp-4h] BYREF
  __int16 v8; // [esp+Eh] [ebp-2h] BYREF

  if ( a2 >= sub_49ADB0(this + 28) && !this[50] || !(unsigned __int8)sub_49AEC0(a2, &v7, &v8) )
    return 0;
  v5 = v8;
  *a3 = this[3] + v7;
  *a4 = this[1] + v5;
  return 1;
}
