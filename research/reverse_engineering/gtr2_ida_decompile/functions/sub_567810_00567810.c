int __thiscall sub_567810(int this)
{
  double v2; // st7
  int v3; // esi
  int v4; // eax
  int v5; // ebp
  int v6; // edi
  int v7; // eax
  char *v9; // eax
  int v10; // [esp+8h] [ebp-8Ch]
  char Buffer[132]; // [esp+10h] [ebp-84h] BYREF

  *(_DWORD *)Buffer = sub_567300((float *)this);
  if ( !*(_DWORD *)Buffer )
  {
    if ( *(float *)(this + 20) > 0.0 )
      *(float *)(this + 20) = *(float *)(this + 20) - dbl_FB1D10;
    if ( *(float *)(this + 24) > 0.0 )
      *(float *)(this + 24) = *(float *)(this + 24) - dbl_FB1D10;
    v2 = *(float *)(this + 28);
    if ( v2 > 0.0 )
    {
      v2 = *(float *)(this + 28) - dbl_FB1D10;
      *(float *)(this + 28) = v2;
    }
    if ( *(_DWORD *)(this + 16) == 1 )
    {
      if ( dword_924FF4[5654 * sub_5511F0(dword_FADD40, 0)] > 0 )
      {
        v9 = sub_41D840(&byte_91CC38, "CLASSIFICATION");
        sprintf(Buffer, "%s", v9);
        sub_562B70((int)Buffer, 100, 50, (int)dword_FFFF00, 0, 0, 1.0, 1.0);
      }
    }
    else if ( *(_DWORD *)(this + 16) == 2 )
    {
      v3 = 6 * ((sub_565F00() - 1) / 6);
      v4 = sub_565F00();
      v5 = v4;
      if ( v3 >= 0 && v3 < v4 )
      {
        v6 = 0;
        while ( v3 < v5 )
        {
          if ( sub_5511F0(dword_FADD40, v3) > 104 )
            return 1;
          v7 = sub_5511F0(dword_FADD40, v3);
          sub_567450(this, v2, v6++, (int)&unk_9204A0 + 22616 * v7);
          ++v3;
          if ( v6 >= 6 )
            return v10;
        }
      }
    }
  }
  return *(_DWORD *)Buffer;
}
