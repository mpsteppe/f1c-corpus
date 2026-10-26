int __thiscall sub_409440(int this, int a2, int a3, int a4)
{
  int v4; // eax
  int v6; // ecx
  BOOL v7; // eax
  int v8; // eax
  _DWORD *v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v17; // eax
  int v18; // eax
  _DWORD *v19; // eax
  int v20; // ecx
  int v21; // eax
  _DWORD *v22; // eax

  v4 = a2;
  if ( byte_7CFE88 || a2 != 3 || !*(_BYTE *)(dword_7C54E0 + 13388) || dword_8AB6E4 == 2 )
  {
    v6 = a3;
  }
  else
  {
    v4 = 2;
    v6 = 0;
  }
  switch ( v4 )
  {
    case 0:
    case 1:
    case 2:
      if ( a4 )
      {
        if ( v4 )
        {
          if ( v4 == 1 )
          {
            v8 = 1;
            *(_DWORD *)(this + 52) = 1;
            *(_DWORD *)(this + 80) = 1;
          }
          else
          {
            *(_DWORD *)(this + 52) = 2;
            v7 = dword_7CFCC8 != 0;
            *(_DWORD *)(this + 80) = 2;
            v8 = v7 ? 0 : 2;
          }
LABEL_15:
          if ( dword_7C54E0 )
            AudioSoundEffectController(v8);
          v9 = (_DWORD *)this;
          if ( !*(_DWORD *)(this + 52) )
            goto LABEL_58;
          ConditionalSubsystemCallWithParameter((_DWORD *)this, dword_7CF680);
          return FloatKeyedFieldSelector((float *)this, *(float *)(this + 52));
        }
        *(_DWORD *)(this + 80) = 0;
        goto LABEL_14;
      }
      v10 = 0;
      if ( v6 )
      {
        LOBYTE(v10) = v6 > 0;
        v10 = 2 * v10 - 1;
      }
      v8 = 1;
      if ( *(_DWORD *)(this + 52) <= 2u )
      {
        v11 = v10 + *(_DWORD *)(this + 80);
        *(_DWORD *)(this + 80) = v11;
        if ( v11 <= 2 )
        {
          if ( v11 < 0 )
            *(_DWORD *)(this + 80) = 2;
        }
        else
        {
          *(_DWORD *)(this + 80) = 0;
        }
      }
      if ( *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
        goto LABEL_34;
      v12 = *(_DWORD *)(this + 80);
      if ( v12 == 1 )
      {
        if ( v10 > 0 && dword_7CFCC8 )
        {
          *(_DWORD *)(this + 80) = 2;
          goto LABEL_34;
        }
      }
      else if ( v12 != 2 || dword_7CFCC8 )
      {
LABEL_34:
        v13 = *(_DWORD *)(this + 80);
        if ( v13 )
        {
          if ( v13 == 1 )
          {
            *(_DWORD *)(this + 52) = 1;
          }
          else
          {
            *(_DWORD *)(this + 52) = 2;
            v8 = dword_7CFCC8 != 0 ? 0 : 2;
          }
          goto LABEL_15;
        }
LABEL_14:
        *(_DWORD *)(this + 52) = 0;
        v8 = 3;
        goto LABEL_15;
      }
      *(_DWORD *)(this + 80) = 0;
      goto LABEL_34;
    case 3:
      *(_DWORD *)(this + 52) = 3;
      goto LABEL_55;
    case 4:
      if ( *(_DWORD *)(this + 52) == 4 && v6 )
      {
        if ( v6 == 1 )
        {
          v14 = *(_DWORD *)(this + 56);
          v15 = *(_DWORD *)(this + 60) + 1;
          *(_DWORD *)(this + 60) = v15;
          if ( v15 >= v14 )
            *(_DWORD *)(this + 60) = 0;
        }
        else if ( --*(_DWORD *)(this + 60) < 0 )
        {
          *(_DWORD *)(this + 60) = *(_DWORD *)(this + 56) - 1;
        }
        goto LABEL_57;
      }
      if ( *(int *)(this + 56) <= 0 )
        goto LABEL_57;
      *(_DWORD *)(this + 52) = 4;
      goto LABEL_55;
    case 5:
    case 6:
    case 7:
    case 8:
      *(_DWORD *)(this + 52) = v4;
      v17 = v4 - 7;
      if ( !v17 )
      {
        v21 = *(_DWORD *)(this + 44);
        if ( !v21 )
          goto LABEL_55;
        v22 = (_DWORD *)(v21 + 188);
        *v22 = dword_5EA550;
        v22[1] = dword_5EA554;
        v22[2] = dword_5EA558;
        dword_5BE900 = 0;
        v20 = *(_DWORD *)(this + 44);
        goto LABEL_54;
      }
      if ( v17 == 1 )
      {
        v18 = *(_DWORD *)(this + 48);
        if ( v18 )
        {
          v19 = (_DWORD *)(v18 + 188);
          *v19 = dword_5EA500;
          v19[1] = dword_5EA504;
          v19[2] = dword_5EA508;
          dword_5BE900 = 0;
          v20 = *(_DWORD *)(this + 48);
LABEL_54:
          (*(void (__thiscall **)(int))(*(_DWORD *)v20 + 28))(v20);
        }
      }
LABEL_55:
      if ( dword_7C54E0 )
        AudioSoundEffectController(0);
LABEL_57:
      v9 = (_DWORD *)this;
LABEL_58:
      ConditionalSubsystemCallWithParameter(v9, 0);
      return FloatKeyedFieldSelector((float *)this, *(float *)(this + 52));
    default:
      return FloatKeyedFieldSelector((float *)this, *(float *)(this + 52));
  }
}
