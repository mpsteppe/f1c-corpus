int *__thiscall sub_4B5630(int this)
{
  int *result; // eax
  int i; // ebp
  _DWORD *v4; // esi
  _DWORD *v5; // eax
  void *v6; // ebx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax

  result = *(int **)(this + 32);
  *(_DWORD *)(this + 40) = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      if ( (unsigned __int8)sub_5001D0(i) && (unsigned __int8)sub_5001F0(i)
        || fabs(*(float *)(i + 880) - *(float *)(this + 48)) <= 2.5 )
      {
        v10 = *(_DWORD *)(this + 40);
        if ( v10 )
          *(_DWORD *)(this + 40) = *(_DWORD *)(v10 + 4);
      }
      else
      {
        v4 = *(_DWORD **)(this + 32);
        v5 = 0;
        if ( v4 )
        {
          while ( *v4 != i )
          {
            v5 = v4;
            v4 = (_DWORD *)v4[1];
            if ( !v4 )
              goto LABEL_21;
          }
          if ( v4 == *(_DWORD **)(this + 40) )
            *(_DWORD *)(this + 40) = v4[1];
          if ( v5 )
            v5[1] = v4[1];
          else
            *(_DWORD *)(this + 32) = v4[1];
          if ( *(_DWORD **)(this + 36) == v4 )
            *(_DWORD *)(this + 36) = v5;
          --*(_DWORD *)(this + 44);
          if ( *((_BYTE *)v4 + 8) )
          {
            v6 = (void *)*v4;
            if ( *v4 )
            {
              nullsub_3();
              sub_587BCF(v6);
            }
          }
          sub_587BCF(v4);
        }
LABEL_21:
        if ( sub_587C03(12) )
          v7 = sub_4BAC20(i, 0);
        else
          v7 = 0;
        v8 = *(_DWORD *)(this + 16);
        if ( v8 )
        {
          *(_DWORD *)(v7 + 4) = v8;
          v9 = *(_DWORD *)(this + 28) + 1;
        }
        else
        {
          v9 = *(_DWORD *)(this + 28) + 1;
          *(_DWORD *)(this + 20) = v7;
          *(_DWORD *)(this + 24) = v7;
        }
        *(_DWORD *)(this + 16) = v7;
        *(_DWORD *)(this + 28) = v9;
      }
      result = *(int **)(this + 40);
      if ( !result )
        break;
    }
  }
  return result;
}
