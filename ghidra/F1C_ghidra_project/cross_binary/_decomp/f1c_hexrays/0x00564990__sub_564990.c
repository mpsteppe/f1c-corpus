// f1c  0x00564990  size=58
int __fastcall sub_564990(_DWORD *a1, int a2)
{
  int v4; // ecx
  int v5; // eax
  int result; // eax
  int v7; // [esp-8h] [ebp-10h]
  int v8; // [esp-4h] [ebp-Ch]

  if ( a2 < *a1 - 1 )
  {
    v8 = a1[2] * (*a1 - a2 - 1);
    v7 = sub_5648B0((int)a1, a2 + 1);
    v5 = sub_5648B0(v4, a2);
    sub_58B130(v5, v7, v8);
  }
  result = *a1 - 1;
  *a1 = result;
  return result;
}
