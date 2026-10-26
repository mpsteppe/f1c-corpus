// f1c  0x005816b0  size=150
char __thiscall sub_5816B0(int **this, int a2, _DWORD *a3)
{
  int *v3; // eax
  int **v4; // ebp
  DWORD v5; // eax
  int **v6; // edi
  int *v7; // eax
  bool v8; // zf
  int v9; // esi
  int *v10; // eax
  int *v11; // eax
  char v13; // [esp+13h] [ebp-1h]

  v3 = this[694];
  v4 = this + 690;
  v13 = 0;
  if ( v3 && ((v5 = WaitForSingleObject(v3, (DWORD)this[695])) == 0 || v5 == 128) )
    v6 = v4;
  else
    v6 = 0;
  v7 = *v6;
  v8 = *v6 == 0;
  v6[2] = *v6;
  if ( !v8 )
  {
    v9 = *v7;
    if ( *v7 )
    {
      while ( (unsigned int)sub_5871F0(v9) != a2 )
      {
        v10 = v6[2];
        if ( v10 )
        {
          v11 = (int *)v10[1];
          v6[2] = v11;
          if ( v11 )
          {
            v9 = *v11;
            if ( *v11 )
              continue;
          }
        }
        goto LABEL_14;
      }
      sub_57B800(a3, v9);
      v13 = 1;
    }
  }
LABEL_14:
  if ( v4[4] )
    ReleaseMutex(v4[4]);
  return v13;
}
