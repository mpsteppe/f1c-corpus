char __thiscall sub_52B550(int this)
{
  int v2; // eax
  void *v3; // edi
  float *v4; // esi
  float *v5; // eax
  double v6; // st7
  float *v7; // eax
  BOOL v8; // esi
  char result; // al
  char *v10; // eax
  double v11; // st7
  _DWORD *v12; // eax
  int v13; // [esp+0h] [ebp-28h]
  float v14; // [esp+10h] [ebp-18h]
  float v15; // [esp+14h] [ebp-14h]
  float v16; // [esp+18h] [ebp-10h]
  float v17[3]; // [esp+1Ch] [ebp-Ch] BYREF

  if ( *(_BYTE *)this )
  {
    if ( *(_BYTE *)(this + 1) )
    {
      v2 = sub_54EC40(0);
      if ( v2 > -1 )
      {
        v3 = off_757C18;
        v4 = (float *)((char *)&unk_9204A0 + 22616 * v2);
        v5 = sub_401290((float *)off_757C18 + 3997, v4 + 3997, v17);
        v14 = *v5;
        v15 = v5[1];
        v16 = v5[2];
        v6 = sub_4211E0(v4, (int)v3);
        if ( v6 >= -50.0 )
        {
          if ( v6 < 50.0 && v6 > -50.0 )
          {
            v7 = (float *)sub_422780((int)v4);
            v6 = v16 * v7[44] + v15 * v7[43] + v14 * v7[42];
          }
          if ( v6 < 30.0 && *(_BYTE *)(this + 1) )
            *(_BYTE *)(this + 1) = 0;
        }
      }
    }
    if ( !dword_FADE9C )
      sub_421A90(off_757C18);
    v8 = *((_DWORD *)off_757C18 + 5213) != 0;
    if ( !*(_DWORD *)(this + 8) && v8 )
      sub_52B2C0((char *)this, 0);
    result = *(_BYTE *)this;
    *(_DWORD *)(this + 8) = v8;
    *((_BYTE *)off_757C18 + 5767) = result;
  }
  else if ( !dword_FADE9C
         || dword_FADE9C == 6
         || dword_FADE9C == 7
         || (v10 = (char *)&unk_9204A0 + 22616 * sub_5511F0(&unk_FADD40, 0), *((_DWORD *)v10 + 3705) == -1)
         || (v11 = sub_577BC0(v10 + 16), v11 <= 0.85000002 * flt_91BDE4)
         || v11 >= 0.94999999 * flt_91BDE4
         || (sub_52B4B0((int)&byte_9034D0, 1), dword_FADE9C <= 1) )
  {
    result = *(_BYTE *)this;
    *((_BYTE *)off_757C18 + 5767) = *(_BYTE *)this;
  }
  else
  {
    v12 = (_DWORD *)sub_416730(&dword_82F4A0);
    *(float *)&v13 = dbl_FB1D18;
    sub_51B2A0(v12, 4, 36, 0, 255, v13, 3);
    result = *(_BYTE *)this;
    *((_BYTE *)off_757C18 + 5767) = *(_BYTE *)this;
  }
  return result;
}
