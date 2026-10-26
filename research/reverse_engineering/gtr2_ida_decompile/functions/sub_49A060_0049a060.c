void __thiscall sub_49A060(_BYTE *this, int a2, char *Buffer, int a4)
{
  int v4; // edi
  char *v5; // ebx
  double v6; // st7
  double v7; // st7
  int v8; // eax
  int v9; // eax
  long double v10; // st7
  int v11; // [esp+18h] [ebp+4h]
  float v12; // [esp+18h] [ebp+4h]
  float Buffera; // [esp+1Ch] [ebp+8h]

  v4 = *(&dword_91E088 + a2);
  v5 = strcpy(Buffer, (const char *)&dword_6FD908);
  if ( v4 && *(int *)dword_B640C8 >= 0 )
  {
    if ( *(int *)dword_B640C8 <= 5 )
    {
      if ( *(_DWORD *)(v4 + 19380) != 3 )
      {
        v8 = 0;
        if ( dword_757C10 > 0 )
        {
          while ( *(_DWORD *)(*(&dword_91E088 + v8) + 19324) != 1 )
          {
            if ( ++v8 >= dword_757C10 )
              return;
          }
          v9 = *(&dword_91E088 + v8);
          if ( v9 )
          {
            Buffera = *(float *)(v9 + 19436);
            v11 = *(int *)(v4 + 19436);
            if ( Buffera > 0.0 && *(float *)&v11 > 0.0 )
            {
              v10 = *(float *)&v11 - Buffera;
              v12 = v10;
              sprintf(v5, "%02.2d:%06.3f", (unsigned int)(unsigned __int64)(v12 * 0.016666668), (double)fmod(v10, 60.0));
            }
          }
        }
      }
    }
    else if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      if ( this[608] )
      {
        if ( *(float *)(v4 + 19436) > 0.0 )
          sprintf(
            v5,
            "%02.2d:%06.3f",
            (unsigned int)(unsigned __int64)(*(float *)(v4 + 19436) * 0.016666668),
            (double)fmod(*(float *)(v4 + 19436), 60.0));
      }
      else if ( *(_DWORD *)(v4 + 19380) == 1 && *(float *)(v4 + 19464) > 0.0 )
      {
        v6 = (double)*(int *)(v4 + 19284) * flt_91BDE4 / *(float *)(v4 + 19464);
        if ( byte_B72478 )
          v7 = v6 * 0.001;
        else
          v7 = v6 * 0.0006213711922373339;
        sprintf(v5, "%6.2f", v7 * 3600.0);
      }
    }
  }
}
