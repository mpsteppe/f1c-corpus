int __fastcall sub_4AC390(int a1)
{
  int v1; // esi
  int v2; // ebx
  int v3; // edi
  int result; // eax
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h]

  v1 = a1 + 508;
  v2 = 0;
  v6 = a1;
  v3 = 0;
  v5 = a1 + 508;
  while ( 1 )
  {
    sub_4AFCA0(*(float *)(a1 + 268));
    result = sub_4AFCD0(v1);
    if ( (_BYTE)result )
    {
      if ( v2 != v3 )
      {
        sub_4AFD00(v1);
        sub_4AFC80(v1);
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
