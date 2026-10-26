void sub_527A00()
{
  double v0; // st7
  int v1; // esi
  int v2; // ebx
  char Buffer[29]; // [esp+10h] [ebp-20h] BYREF
  __int16 v4; // [esp+2Dh] [ebp-3h]
  char v5; // [esp+2Fh] [ebp-1h]

  if ( flt_7DA9B0 > 0.0 )
  {
    v0 = flt_7DA9B0 - dbl_7DA9C0;
    dword_7DA9B4 = LODWORD(flt_7DA9B0);
    flt_7DA9B0 = v0;
    if ( v0 > 0.0 )
    {
      v1 = (__int64)floor(*(float *)&dword_7DA9B4);
      v2 = (__int64)floor(flt_7DA9B0);
      if ( v1 != v2 )
      {
        Buffer[0] = byte_629120;
        memset(&Buffer[1], 0, 0x1Cu);
        v4 = 0;
        v5 = 0;
        sprintf(Buffer, "... %d ...", v1 + 1);
        sub_45D270(&byte_764D68, Buffer, 1);
        sprintf(Buffer, "... %d ...", v2 + 1);
        sub_45D100(&byte_764D68, (int)Buffer, 3, 16909060, 0);
      }
    }
    else
    {
      sub_45D270(&byte_764D68, a1, 1);
      dword_766180 = 0;
      if ( sub_42DBA0() )
        sub_51BC20((float *)(dword_75AACC + 84), 0, 1);
      dword_7DA9B4 = 0;
      flt_7DA9B0 = 0.0;
    }
  }
}
