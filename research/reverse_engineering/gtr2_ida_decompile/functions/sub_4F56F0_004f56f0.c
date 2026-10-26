int __thiscall sub_4F56F0(int this)
{
  int result; // eax
  int v3; // ebp
  int v4; // edi
  int *v5; // ecx
  bool v6; // bl
  int v7; // ebp
  int v8; // edi
  int v9; // ecx
  int v10; // ecx
  int v11; // edi
  int v12; // ecx
  int v13; // edx
  int v14; // eax
  int *v15; // eax
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // ecx
  int v26; // ecx

  result = *(_DWORD *)(this + 160);
  if ( result )
  {
    v3 = *(_DWORD *)(result + 20);
    if ( v3 )
    {
      v4 = *(_DWORD *)(this + 168);
      if ( v4 )
      {
        if ( !(unsigned __int8)sub_405250() )
          goto LABEL_9;
        v5 = *(int **)(this + 4);
        v6 = *(float *)(*(_DWORD *)(v4 + 60) + 20) * (double)*(int *)(v4 + 44) + *(double *)v4 >= *(float *)&v5[v3 + 42];
        if ( v3 >= 1 && v3 <= 4 )
          sub_4EE320(82, *v5);
        if ( v6 )
        {
LABEL_9:
          v7 = *(_DWORD *)(*(_DWORD *)(this + 140) + 8);
          v8 = *(_DWORD *)(this + 168);
          if ( (unsigned __int8)sub_405250() )
            sub_5BC080(v7, v8, *(_DWORD *)(*(_DWORD *)(this + 160) + 12));
          *(_DWORD *)(this + 168) = 0;
        }
      }
    }
    v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 140) + 8) + 532);
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 12))(v9);
    if ( (_BYTE)result )
    {
      v10 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 140) + 8) + 532);
      result = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 28))(v10);
      v11 = result;
      if ( result )
      {
        if ( *(_DWORD *)(result + 60) != *(_DWORD *)(*(_DWORD *)(this + 160) + 112) )
        {
          while ( 1 )
          {
            v12 = *(_DWORD *)(this + 152);
            v13 = *(_DWORD *)(this + 164) + 1;
            *(_DWORD *)(this + 164) = v13;
            if ( v13 == v12 )
              break;
            v14 = *(_DWORD *)(*(_DWORD *)(this + 160) + 20);
            if ( v14 >= 1 && v14 <= 4 )
              sub_4EE120(dword_B6F1C8, 82, 0);
            v15 = (int *)(*(_DWORD *)(this + 160) + 120);
            *(_DWORD *)(this + 160) = v15;
            *(_DWORD *)(this + 168) = v11;
            if ( v15[22] )
            {
              if ( *(_DWORD *)(this + 164) < *(_DWORD *)(this + 152) - 1 && v15[59] == 36 )
                v16 = (int)(v15 + 30);
              else
                v16 = 0;
              sub_4F4930(this, v15[22], v15[23], v16);
            }
            v17 = *(_DWORD *)(this + 176);
            if ( *(_DWORD *)(*(_DWORD *)(this + 160) + 84) )
            {
              if ( v17 )
                (*(void (__thiscall **)(int, int))(*(_DWORD *)v17 + 20))(v17, 1);
              v18 = *(_DWORD *)(this + 180);
              if ( v18 )
                (*(void (__thiscall **)(int, int))(*(_DWORD *)v18 + 20))(v18, 1);
              v19 = *(_DWORD *)(this + 172);
              if ( v19 )
                (*(void (__thiscall **)(int, int))(*(_DWORD *)v19 + 20))(v19, 1);
              v20 = *(_DWORD *)(*(_DWORD *)(this + 160) + 84);
              if ( v20 == 1 )
              {
                v21 = *(_DWORD *)(this + 168);
                v22 = *(_DWORD *)(this + 172);
                *(_DWORD *)(v22 + 28) = 1;
                *(_DWORD *)(v22 + 32) = v21;
              }
              else if ( v20 == 3 )
              {
                v23 = *(_DWORD *)(this + 168);
                v24 = *(_DWORD *)(this + 172);
                *(_DWORD *)(v24 + 28) = 2;
                *(_DWORD *)(v24 + 32) = v23;
              }
            }
            else
            {
              if ( v17 )
                (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v17 + 20))(v17, 0);
              v25 = *(_DWORD *)(this + 180);
              if ( v25 )
                (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v25 + 20))(v25, 0);
              v26 = *(_DWORD *)(this + 172);
              if ( v26 )
                (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v26 + 20))(v26, 0);
            }
            if ( *(_DWORD *)(*(_DWORD *)(this + 160) + 100) )
              sub_405F00(*(_BYTE **)(this + 140), 0);
            result = *(_DWORD *)(*(_DWORD *)(this + 160) + 20);
            if ( result >= 1 && result <= 4 )
              result = sub_4EE320(82, **(_DWORD **)(this + 4));
            if ( *(_DWORD *)(v11 + 60) == *(_DWORD *)(*(_DWORD *)(this + 160) + 112) )
              return result;
          }
          result = 0;
          *(_DWORD *)(this + 164) = 99;
          *(_DWORD *)(this + 160) = 0;
          *(_DWORD *)(this + 168) = 0;
        }
      }
    }
  }
  return result;
}
