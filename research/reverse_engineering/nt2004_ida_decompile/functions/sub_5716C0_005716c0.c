char __thiscall sub_5716C0(int **this, int a2, int a3, char a4)
{
  int *v4; // eax
  int **v5; // ebp
  DWORD v6; // eax
  int **v7; // edi
  int *v8; // eax
  bool v9; // zf
  int v10; // esi
  int *v11; // eax
  int *v12; // eax
  char v14; // [esp+13h] [ebp-1h]

  v4 = this[694];
  v5 = this + 690;
  v14 = 0;
  if ( v4 && ((v6 = WaitForSingleObject(v4, (DWORD)this[695])) == 0 || v6 == 128) )
    v7 = v5;
  else
    v7 = 0;
  v8 = *v7;
  v9 = *v7 == 0;
  v7[2] = *v7;
  if ( !v9 )
  {
    v10 = *v8;
    if ( *v8 )
    {
      while ( (unsigned int)sub_577280(v10) != a2 )
      {
        v11 = v7[2];
        if ( v11 )
        {
          v12 = (int *)v11[1];
          v7[2] = v12;
          if ( v12 )
          {
            v10 = *v12;
            if ( *v12 )
              continue;
          }
        }
        goto LABEL_16;
      }
      sub_5776C0(a3 + 4);
      if ( a4 )
        sub_5772C0(1);
      v14 = 1;
    }
  }
LABEL_16:
  if ( v5[4] )
    ReleaseMutex(v5[4]);
  return v14;
}
