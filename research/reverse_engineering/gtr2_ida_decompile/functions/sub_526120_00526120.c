int *__thiscall sub_526120(int this)
{
  int *result; // eax
  int i; // ebp
  int v4; // esi
  int v5; // eax
  void *v6; // ebx
  int v7; // eax

  result = *(int **)(this + 32);
  *(_DWORD *)(this + 40) = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      if ( (unsigned __int8)sub_599CD0(i) && (unsigned __int8)sub_599CF0(i)
        || fabs(*(float *)(i + 1712) - *(float *)(this + 48)) <= 2.5 )
      {
        v7 = *(_DWORD *)(this + 40);
        if ( v7 )
          *(_DWORD *)(this + 40) = *(_DWORD *)(v7 + 4);
      }
      else
      {
        v4 = *(_DWORD *)(this + 32);
        v5 = 0;
        if ( v4 )
        {
          while ( *(_DWORD *)v4 != i )
          {
            v5 = v4;
            v4 = *(_DWORD *)(v4 + 4);
            if ( !v4 )
              goto LABEL_9;
          }
          if ( v4 == *(_DWORD *)(this + 40) )
            *(_DWORD *)(this + 40) = *(_DWORD *)(v4 + 4);
          if ( v5 )
            *(_DWORD *)(v5 + 4) = *(_DWORD *)(v4 + 4);
          else
            *(_DWORD *)(this + 32) = *(_DWORD *)(v4 + 4);
          if ( *(_DWORD *)(this + 36) == v4 )
            *(_DWORD *)(this + 36) = v5;
          --*(_DWORD *)(this + 44);
          if ( *(_BYTE *)(v4 + 8) )
          {
            v6 = *(void **)v4;
            if ( *(_DWORD *)v4 )
            {
              j_nullsub_7(*(void **)v4);
              j__free(v6);
            }
          }
          j__free((void *)v4);
        }
LABEL_9:
        sub_5E5780(i, 0);
      }
      result = *(int **)(this + 40);
      if ( !result )
        break;
    }
  }
  return result;
}
