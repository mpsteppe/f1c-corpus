// f1c  0x00584cd0  size=247
bool __thiscall sub_584CD0(_DWORD *this, _DWORD *a2)
{
  bool v3; // bl
  void *v4; // eax
  DWORD v5; // eax
  int *v6; // eax
  int v7; // ebx
  _DWORD *v8; // esi
  _DWORD *v9; // eax
  void *v10; // edi
  void *v12; // ebp

  v3 = 0;
  v4 = (void *)this[341];
  if ( v4 )
  {
    v5 = WaitForSingleObject(v4, this[342]);
    if ( !v5 || v5 == 128 )
    {
      v6 = (int *)this[337];
      v7 = 0;
      if ( v6 )
      {
        *((_BYTE *)v6 + 8) = 0;
        v7 = *v6;
        if ( *v6 && (v8 = (_DWORD *)this[337], v9 = 0, v8) )
        {
          while ( *v8 != v7 )
          {
            v9 = v8;
            v8 = (_DWORD *)v8[1];
            if ( !v8 )
              goto LABEL_9;
          }
          if ( v8 == (_DWORD *)this[339] )
            this[339] = v8[1];
          if ( v9 )
            v9[1] = v8[1];
          else
            this[337] = v8[1];
          if ( (_DWORD *)this[338] == v8 )
            this[338] = v9;
          --this[340];
          if ( *((_BYTE *)v8 + 8) )
          {
            v12 = (void *)*v8;
            if ( *v8 )
            {
              sub_5867B0(*v8);
              sub_587BCF(v12);
            }
          }
          sub_587BCF(v8);
        }
        else
        {
LABEL_9:
          v7 = 0;
        }
      }
      *a2 = v7;
      v3 = v7 != 0;
      v10 = (void *)this[341];
      if ( v10 )
        ReleaseMutex(v10);
    }
  }
  return v3;
}
