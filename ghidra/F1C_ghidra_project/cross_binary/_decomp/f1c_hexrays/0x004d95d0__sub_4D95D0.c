// f1c  0x004d95d0  size=180
int __stdcall sub_4D95D0(int a1, int a2, float a3, float a4)
{
  char v4; // bl
  int v5; // edi
  double v6; // st7
  int v7; // eax
  int v8; // ecx
  float v10; // [esp+0h] [ebp-Ch]
  float v11; // [esp+4h] [ebp-8h]
  float v12; // [esp+8h] [ebp-4h]
  char v13; // [esp+1Ch] [ebp+10h]

  v10 = a4 + 160.0;
  v4 = 0;
  v5 = 0;
  v6 = a4;
  v13 = 0;
  if ( dword_5C329C > 0 )
  {
    while ( 1 )
    {
      v7 = dword_7C54F0[v5];
      v8 = *(_DWORD *)(v7 + 16480);
      if ( a1 == v8 )
        break;
      if ( a2 == v8 )
      {
        v11 = v6 - 32.0;
        v12 = a3 + 64.0;
        sub_4D9690(v7, v12, v11);
        v4 = 1;
      }
      if ( v13 )
        goto LABEL_7;
LABEL_8:
      if ( ++v5 >= dword_5C329C )
        return 0;
    }
    sub_4D9690(v7, a3, v10);
    v13 = 1;
LABEL_7:
    if ( v4 )
      return 0;
    goto LABEL_8;
  }
  return 0;
}
