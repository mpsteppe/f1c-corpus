// f1c  0x00495b60  size=106
int __fastcall sub_495B60(int a1)
{
  int v1; // esi
  int v2; // ebx
  int v3; // edi
  int result; // eax
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  v1 = a1 + 5628;
  v2 = 0;
  v6 = a1;
  v3 = 0;
  v5 = a1 + 5628;
  while ( 1 )
  {
    sub_499A20(*(float *)(a1 + 192));
    result = sub_499A50(v1);
    if ( (_BYTE)result )
    {
      if ( v2 != v3 )
      {
        sub_499A70(v1);
        sub_499A00(v1);
      }
      ++v2;
      result = v5 + 12;
      v5 += 12;
    }
    ++v3;
    v1 += 12;
    if ( v3 >= 4 )
      break;
    a1 = v6;
  }
  return result;
}
