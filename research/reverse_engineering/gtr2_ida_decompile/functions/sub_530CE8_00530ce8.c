// positive sp value has been detected, the output may be wrong!
int __userpurge sub_530CE8@<eax>(int result@<eax>, int a2)
{
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  char v10; // [esp+3h] [ebp-9h]
  int v11; // [esp+4h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]
  int v13; // [esp+10h] [ebp+4h]

  v3 = dword_757C10;
  v4 = 0;
  v11 = result;
  v10 = 0;
  v13 = 1;
  if ( dword_757C10 >= 1 )
  {
    while ( 1 )
    {
      v5 = 0;
      if ( v3 > 0 )
        break;
LABEL_21:
      result = ++v13;
      if ( v13 > v3 )
        return result;
    }
    while ( 1 )
    {
      v6 = *(&dword_91E088 + v5);
      v7 = *(_DWORD *)(v6 + 19324);
      if ( v7 == v13 )
      {
        if ( v6 == a2 )
          goto LABEL_18;
        if ( !v10 )
        {
          if ( v11 == 6 )
          {
            v8 = *(_DWORD *)(v6 + 19284);
            v9 = *(_DWORD *)(a2 + 19284);
            if ( v8 >= v9 && (v8 != v9 || *(float *)(v6 + 19432) <= (double)*(float *)(a2 + 19432)) )
              goto LABEL_19;
          }
          else if ( *(float *)(v6 + 19436) <= (double)*(float *)(a2 + 19436) && *(float *)(v6 + 19436) >= 0.0 )
          {
            goto LABEL_19;
          }
          v10 = 1;
          if ( *(_DWORD *)(a2 + 19324) - 1 == v7 )
            v13 = v3 + 1;
          v4 = v6;
          sub_52C360(v7);
          sub_52C360(*(_DWORD *)(v6 + 19324) + 1);
          goto LABEL_19;
        }
        if ( v4 != v6 )
        {
          v4 = *(&dword_91E088 + v5);
          sub_52C360(v7 + 1);
          if ( v11 == *(_DWORD *)(v6 + 19324) )
LABEL_18:
            retaddr = (_UNKNOWN *)(v3 + 1);
LABEL_19:
          v5 = v3;
        }
      }
      if ( ++v5 >= v3 )
        goto LABEL_21;
    }
  }
  return result;
}
