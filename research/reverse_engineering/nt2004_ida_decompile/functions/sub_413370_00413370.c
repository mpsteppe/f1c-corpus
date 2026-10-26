char __thiscall sub_413370(_DWORD *this, unsigned __int8 a2, const char *a3)
{
  int v4; // ecx
  int *v5; // eax
  int v6; // esi
  char NewFilename[125]; // [esp+18h] [ebp-100h] BYREF
  __int16 v9; // [esp+95h] [ebp-83h]
  char v10; // [esp+97h] [ebp-81h]
  char OldFilename[125]; // [esp+98h] [ebp-80h] BYREF
  __int16 v12; // [esp+115h] [ebp-3h]
  char v13; // [esp+117h] [ebp-1h]

  if ( a3 )
  {
    if ( strlen(a3) )
    {
      v4 = a2;
      if ( a2 < (int)this[27] )
      {
        v5 = (int *)this[24];
        if ( a2 )
        {
          while ( v5 )
          {
            v5 = (int *)v5[1];
            if ( --v4 <= 0 )
              goto LABEL_7;
          }
        }
        else
        {
LABEL_7:
          if ( v5 )
          {
            v6 = *v5;
            if ( *v5 )
            {
              OldFilename[0] = byte_629120;
              memset(&OldFilename[1], 0, 0x7Cu);
              v12 = 0;
              v13 = 0;
              NewFilename[0] = byte_629120;
              memset(&NewFilename[1], 0, 0x7Cu);
              v9 = 0;
              v10 = 0;
              (*(void (__thiscall **)(_DWORD *, int, char *, int))(*this + 44))(this, v6, OldFilename, 127);
              sub_578600(a3);
              (*(void (__thiscall **)(_DWORD *, int, char *, int))(*this + 44))(this, v6, NewFilename, 127);
              rename(OldFilename, NewFilename);
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}
