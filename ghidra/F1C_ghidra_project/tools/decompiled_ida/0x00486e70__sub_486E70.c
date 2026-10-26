// Address: 0x00486e70
// Size: 86 bytes
// Name: sub_486E70
// Type: BOOL __thiscall(_BYTE *this, int, int)
// Source: IDA Hex-Rays decompilation

BOOL __thiscall sub_486E70(_BYTE *this, int a2, int a3)
{
  BOOL result; // eax
  int v4; // [esp+10h] [ebp-10h] BYREF
  int v5; // [esp+14h] [ebp-Ch] BYREF
  int v6; // [esp+18h] [ebp-8h] BYREF
  int v7; // [esp+1Ch] [ebp-4h] BYREF

  result = 0;
  if ( this[101] )
  {
    (*(void (__thiscall **)(_BYTE *, int *, int *, int *, int *))(*(_DWORD *)this + 8))(this, &v6, &v7, &v4, &v5);
    if ( a2 >= v4 && a2 <= v5 && a3 >= v6 && a3 <= v7 )
      return 1;
  }
  return result;
}
