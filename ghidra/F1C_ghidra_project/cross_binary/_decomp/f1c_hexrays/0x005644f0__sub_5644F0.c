// f1c  0x005644f0  size=54
int *__fastcall sub_5644F0(int a1, int a2)
{
  int *result; // eax
  int v4; // ecx
  int v5; // [esp+4h] [ebp-Ch] BYREF
  int v6; // [esp+8h] [ebp-8h] BYREF

  v5 = a2;
  result = (int *)sub_5647D0(*(_DWORD *)(a1 + 16), &v5);
  if ( result )
  {
    v4 = *(_DWORD *)(a1 + 12);
    v6 = *result;
    return (int *)sub_5647D0(v4, &v6);
  }
  return result;
}
