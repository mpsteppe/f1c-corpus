int __thiscall sub_48CCB0(_DWORD *this, _DWORD *a2, int a3, _DWORD *a4, int a5)
{
  int result; // eax
  int v7; // ebp
  int v8; // edi
  int v9; // edi
  int v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  int v14; // ebx
  int v15; // eax
  int v16; // ebx
  int v17; // ecx
  int v18; // eax
  int *v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // edi
  int v28; // ebx
  int v29; // ecx
  int v30; // edi
  int v31; // ebp
  int v32; // eax
  int v33; // ebx
  int v34; // eax
  _DWORD *v35; // edi
  int v36; // eax
  int v37; // ecx
  int v38; // ebx
  int v39; // ebp
  int v40; // eax
  int v41; // edx
  int v42; // eax
  int v43; // eax
  int v44; // [esp-18h] [ebp-5Ch]
  int v45; // [esp-14h] [ebp-58h]
  int v46; // [esp+10h] [ebp-34h]
  int v47; // [esp+10h] [ebp-34h]
  int v48; // [esp+14h] [ebp-30h]
  int v49; // [esp+18h] [ebp-2Ch]
  int v50; // [esp+18h] [ebp-2Ch]
  int v51; // [esp+1Ch] [ebp-28h]
  int v52; // [esp+20h] [ebp-24h]
  int v53; // [esp+24h] [ebp-20h]
  int v54; // [esp+28h] [ebp-1Ch]
  int v55; // [esp+2Ch] [ebp-18h]
  int v56; // [esp+30h] [ebp-14h]
  char v57[4]; // [esp+34h] [ebp-10h] BYREF
  int v58; // [esp+38h] [ebp-Ch] BYREF
  char v59[4]; // [esp+3Ch] [ebp-8h] BYREF
  int v60; // [esp+40h] [ebp-4h] BYREF

  result = -1;
  if ( this[5] != -1 || this[6] != -1 || this[7] != -1 || this[8] != -1 )
  {
    v7 = 0;
    if ( (int)this[202] > 0 )
    {
      v8 = (*(int (__thiscall **)(_DWORD *))(*this + 32))(this);
      v9 = v8 - (*(int (__thiscall **)(_DWORD *))(*this + 24))(this);
      v10 = (*(int (__thiscall **)(_DWORD *))(*this + 36))(this);
      v55 = v10 - (*(int (__thiscall **)(_DWORD *))(*this + 28))(this);
      v11 = (*(int (__thiscall **)(_DWORD *))(*this + 24))(this);
      v12 = v9;
      v13 = this[203];
      v46 = v12 / 2 + v11 - this[205] % v13;
      v14 = this[205] / v13;
      v15 = (v46 - (*(int (__thiscall **)(_DWORD *))(*this + 24))(this)) / v13 + 1;
      v16 = v14 - v15;
      v47 = v46 - v15 * v13;
      v48 = v16;
      if ( v16 < 0 )
      {
        do
          v16 += this[202];
        while ( v16 < 0 );
        v48 = v16;
      }
      if ( v47 < (*(int (__thiscall **)(_DWORD *))(*this + 32))(this) )
      {
        while ( 1 )
        {
          v17 = v16;
          if ( v16 < 0 || v16 >= this[202] )
          {
            this[201] = 0;
          }
          else
          {
            this[201] = this[199];
            if ( v16 > 0 )
            {
              do
              {
                v18 = this[201];
                if ( !v18 )
                  break;
                --v17;
                this[201] = *(_DWORD *)(v18 + 4);
              }
              while ( v17 > 0 );
            }
          }
          v19 = (int *)this[201];
          if ( !v19 )
            break;
          v24 = *v19;
          v52 = v24;
          if ( !v24 )
            goto LABEL_19;
          v25 = *(_DWORD *)(v24 + 4);
          if ( !v25 )
            goto LABEL_19;
          v26 = *(_DWORD *)(v25 + 12);
          if ( !v26 )
            goto LABEL_19;
          v20 = *(_DWORD *)(v26 + 28);
          v49 = v20;
LABEL_20:
          if ( v52 && (v21 = *(_DWORD *)(v52 + 4)) != 0 && (v22 = *(_DWORD *)(v21 + 12)) != 0 )
          {
            v23 = *(_DWORD *)(v22 + 32);
            v51 = v23;
          }
          else
          {
            v51 = 0;
            v23 = 0;
          }
          if ( v20 > 0 && v23 > 0 )
          {
            v27 = this[203] - v20;
            v28 = v55 - v23;
            if ( v27 <= 0 )
            {
              v53 = 0;
              v29 = 0;
            }
            else
            {
              v29 = v27 / 2;
              v53 = v27 / 2;
            }
            if ( v28 > 0 )
              v7 = v28 / 2;
            v54 = v47 + v29;
            v56 = v7 + (*(int (__thiscall **)(_DWORD *))(*this + 28))(this);
            if ( v27 <= 0 )
            {
              v31 = v27 / -2;
              v30 = v49 - -2 * (v27 / 2);
            }
            else
            {
              v30 = v49;
              v31 = 0;
            }
            if ( v28 <= 0 )
            {
              v50 = v28 / -2;
              v51 -= 2 * (v28 / -2);
            }
            else
            {
              v50 = 0;
            }
            if ( v47 >= (*(int (__thiscall **)(_DWORD *))(*this + 24))(this) )
            {
              v33 = v54;
            }
            else
            {
              v32 = (*(int (__thiscall **)(_DWORD *))(*this + 24))(this) - v53 - v47;
              v33 = v54;
              if ( v32 > 0 )
              {
                v31 += v32;
                v33 = v32 + v54;
                v30 -= v32;
              }
            }
            if ( v30 >= (*(int (__thiscall **)(_DWORD *))(*this + 32))(this) - v33 )
              v30 = (*(int (__thiscall **)(_DWORD *))(*this + 32))(this) - v33;
            if ( v30 > 0 && v51 > 0 )
            {
              v34 = sub_495150(&unk_7CDE00);
              sub_494A30(*(_DWORD *)(*(_DWORD *)(v52 + 4) + 12), v31, v50, v34, v33, v56, v30, v51, 0, 0);
            }
            v16 = v48;
            v7 = 0;
          }
          v48 = ++v16;
          if ( v16 > this[202] - 1 )
          {
            v48 = 0;
            v16 = 0;
          }
          v47 += this[203];
          if ( v47 >= (*(int (__thiscall **)(_DWORD *))(*this + 32))(this) )
            goto LABEL_55;
        }
        v52 = 0;
LABEL_19:
        v49 = 0;
        v20 = 0;
        goto LABEL_20;
      }
LABEL_55:
      if ( sub_486830(this) )
      {
        if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*this + 20))(this) )
          (*(void (__thiscall **)(_DWORD *, int *, char *, int *, char *))(*this + 8))(this, &v60, v59, &v58, v57);
        (*(void (__thiscall **)(_DWORD *))(*this + 12))(this);
        v35 = (_DWORD *)sub_486460(this, this[33]);
        v36 = this[34];
        if ( v36 > 0 )
        {
          do
          {
            if ( v35 )
              v35 = (_DWORD *)v35[10];
            --v36;
          }
          while ( v36 );
        }
        if ( v35 )
        {
          *a4 = this[3];
          v37 = this[1];
          *a2 = v37;
          v38 = v35[1] - *v35;
          v39 = v35[3] - v35[2];
          v40 = *(_DWORD *)(v35[8] + 12);
          v41 = *(_DWORD *)(v40 + 28);
          v42 = *(_DWORD *)(v40 + 32);
          if ( v38 > v41 )
            v38 = v41;
          if ( v39 > v42 )
            v39 = v42;
          v45 = v37;
          v44 = *a4;
          v43 = sub_495150(&unk_7CDE00);
          sub_494A30(*(_DWORD *)(v35[8] + 12), *v35, v35[2], v43, v44, v45, v38, v39, 0, 0);
          (*(void (__thiscall **)(_DWORD *, _DWORD, int, _DWORD, int))(*this + 16))(
            this,
            *a2,
            *a2 + v39,
            *a4,
            *a4 + v38);
        }
        return 0;
      }
      else
      {
        return -1;
      }
    }
  }
  return result;
}
