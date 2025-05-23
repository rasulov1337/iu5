PGDMP      7                |            it-firm    16.2    16.2 I    @           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            A           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            B           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            C           1262    16398    it-firm    DATABASE     }   CREATE DATABASE "it-firm" WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'Russian_Russia.1251';
    DROP DATABASE "it-firm";
                postgres    false            �            1259    16495    accounts    TABLE     �   CREATE TABLE public.accounts (
    id bigint NOT NULL,
    client_id bigint,
    login character varying(16) NOT NULL,
    password character varying(16) NOT NULL,
    type character varying(10) DEFAULT 'client'::character varying NOT NULL
);
    DROP TABLE public.accounts;
       public         heap    postgres    false            �            1259    16499    accounts_id_seq    SEQUENCE     x   CREATE SEQUENCE public.accounts_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 &   DROP SEQUENCE public.accounts_id_seq;
       public          postgres    false    215            D           0    0    accounts_id_seq    SEQUENCE OWNED BY     C   ALTER SEQUENCE public.accounts_id_seq OWNED BY public.accounts.id;
          public          postgres    false    216            �            1259    16500    clients    TABLE     �   CREATE TABLE public.clients (
    id bigint NOT NULL,
    fullname text,
    telephone text,
    address text,
    email text,
    is_company boolean,
    CONSTRAINT no_empty_name CHECK ((fullname <> ''::text))
);
    DROP TABLE public.clients;
       public         heap    postgres    false            �            1259    16505    clients_id_seq    SEQUENCE     w   CREATE SEQUENCE public.clients_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 %   DROP SEQUENCE public.clients_id_seq;
       public          postgres    false    217            E           0    0    clients_id_seq    SEQUENCE OWNED BY     A   ALTER SEQUENCE public.clients_id_seq OWNED BY public.clients.id;
          public          postgres    false    218            �            1259    16506 
   dev_groups    TABLE     h   CREATE TABLE public.dev_groups (
    id bigint NOT NULL,
    name text NOT NULL,
    tech_stack text
);
    DROP TABLE public.dev_groups;
       public         heap    postgres    false            �            1259    16511    dev_groups_id_seq    SEQUENCE     z   CREATE SEQUENCE public.dev_groups_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 (   DROP SEQUENCE public.dev_groups_id_seq;
       public          postgres    false    219            F           0    0    dev_groups_id_seq    SEQUENCE OWNED BY     G   ALTER SEQUENCE public.dev_groups_id_seq OWNED BY public.dev_groups.id;
          public          postgres    false    220            �            1259    16512 	   employees    TABLE     1  CREATE TABLE public.employees (
    id bigint NOT NULL,
    fullname text NOT NULL,
    birth_date date,
    salary numeric NOT NULL,
    hire_date date,
    dev_group_id bigint,
    CONSTRAINT no_empty_name CHECK ((fullname <> ''::text)),
    CONSTRAINT positif_salary CHECK ((salary > (0)::numeric))
);
    DROP TABLE public.employees;
       public         heap    postgres    false            �            1259    16582    employees_hardwares    TABLE     �   CREATE TABLE public.employees_hardwares (
    id bigint NOT NULL,
    employee_id bigint NOT NULL,
    hardware_id bigint NOT NULL
);
 '   DROP TABLE public.employees_hardwares;
       public         heap    postgres    false            �            1259    16581    employees_hardwares_id_seq    SEQUENCE     �   CREATE SEQUENCE public.employees_hardwares_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 1   DROP SEQUENCE public.employees_hardwares_id_seq;
       public          postgres    false    232            G           0    0    employees_hardwares_id_seq    SEQUENCE OWNED BY     Y   ALTER SEQUENCE public.employees_hardwares_id_seq OWNED BY public.employees_hardwares.id;
          public          postgres    false    231            �            1259    16517    employees_id_seq    SEQUENCE     y   CREATE SEQUENCE public.employees_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 '   DROP SEQUENCE public.employees_id_seq;
       public          postgres    false    221            H           0    0    employees_id_seq    SEQUENCE OWNED BY     E   ALTER SEQUENCE public.employees_id_seq OWNED BY public.employees.id;
          public          postgres    false    222            �            1259    16528    hardware    TABLE     �   CREATE TABLE public.hardware (
    id bigint NOT NULL,
    internet_speed integer,
    gpu text,
    cpu text,
    ram integer
);
    DROP TABLE public.hardware;
       public         heap    postgres    false            �            1259    16518    orders    TABLE     �   CREATE TABLE public.orders (
    id bigint NOT NULL,
    price numeric,
    deadline date,
    client_id bigint,
    creation_date date,
    done boolean
);
    DROP TABLE public.orders;
       public         heap    postgres    false            �            1259    16521    orders_id_seq    SEQUENCE     v   CREATE SEQUENCE public.orders_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 $   DROP SEQUENCE public.orders_id_seq;
       public          postgres    false    223            I           0    0    orders_id_seq    SEQUENCE OWNED BY     ?   ALTER SEQUENCE public.orders_id_seq OWNED BY public.orders.id;
          public          postgres    false    224            �            1259    16522    programs    TABLE     �   CREATE TABLE public.programs (
    id bigint NOT NULL,
    repo text,
    name text,
    tech_stack text,
    order_id bigint,
    dev_group_id bigint
);
    DROP TABLE public.programs;
       public         heap    postgres    false            �            1259    16527    programs_id_seq    SEQUENCE     x   CREATE SEQUENCE public.programs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 &   DROP SEQUENCE public.programs_id_seq;
       public          postgres    false    225            J           0    0    programs_id_seq    SEQUENCE OWNED BY     C   ALTER SEQUENCE public.programs_id_seq OWNED BY public.programs.id;
          public          postgres    false    226            �            1259    16533    tech_eqs_id_seq    SEQUENCE     x   CREATE SEQUENCE public.tech_eqs_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 &   DROP SEQUENCE public.tech_eqs_id_seq;
       public          postgres    false    227            K           0    0    tech_eqs_id_seq    SEQUENCE OWNED BY     C   ALTER SEQUENCE public.tech_eqs_id_seq OWNED BY public.hardware.id;
          public          postgres    false    228            �            1259    16534    tech_stacks    TABLE     Q   CREATE TABLE public.tech_stacks (
    id bigint NOT NULL,
    stack_name text
);
    DROP TABLE public.tech_stacks;
       public         heap    postgres    false            �            1259    16539    tech_stacks_id_seq    SEQUENCE     {   CREATE SEQUENCE public.tech_stacks_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;
 )   DROP SEQUENCE public.tech_stacks_id_seq;
       public          postgres    false    229            L           0    0    tech_stacks_id_seq    SEQUENCE OWNED BY     I   ALTER SEQUENCE public.tech_stacks_id_seq OWNED BY public.tech_stacks.id;
          public          postgres    false    230            x           2604    16540    accounts id    DEFAULT     j   ALTER TABLE ONLY public.accounts ALTER COLUMN id SET DEFAULT nextval('public.accounts_id_seq'::regclass);
 :   ALTER TABLE public.accounts ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    216    215            z           2604    16541 
   clients id    DEFAULT     h   ALTER TABLE ONLY public.clients ALTER COLUMN id SET DEFAULT nextval('public.clients_id_seq'::regclass);
 9   ALTER TABLE public.clients ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    218    217            {           2604    16542    dev_groups id    DEFAULT     n   ALTER TABLE ONLY public.dev_groups ALTER COLUMN id SET DEFAULT nextval('public.dev_groups_id_seq'::regclass);
 <   ALTER TABLE public.dev_groups ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    220    219            |           2604    16543    employees id    DEFAULT     l   ALTER TABLE ONLY public.employees ALTER COLUMN id SET DEFAULT nextval('public.employees_id_seq'::regclass);
 ;   ALTER TABLE public.employees ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    222    221            �           2604    16585    employees_hardwares id    DEFAULT     �   ALTER TABLE ONLY public.employees_hardwares ALTER COLUMN id SET DEFAULT nextval('public.employees_hardwares_id_seq'::regclass);
 E   ALTER TABLE public.employees_hardwares ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    232    231    232                       2604    16546    hardware id    DEFAULT     j   ALTER TABLE ONLY public.hardware ALTER COLUMN id SET DEFAULT nextval('public.tech_eqs_id_seq'::regclass);
 :   ALTER TABLE public.hardware ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    228    227            }           2604    16544 	   orders id    DEFAULT     f   ALTER TABLE ONLY public.orders ALTER COLUMN id SET DEFAULT nextval('public.orders_id_seq'::regclass);
 8   ALTER TABLE public.orders ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    224    223            ~           2604    16545    programs id    DEFAULT     j   ALTER TABLE ONLY public.programs ALTER COLUMN id SET DEFAULT nextval('public.programs_id_seq'::regclass);
 :   ALTER TABLE public.programs ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    226    225            �           2604    16547    tech_stacks id    DEFAULT     p   ALTER TABLE ONLY public.tech_stacks ALTER COLUMN id SET DEFAULT nextval('public.tech_stacks_id_seq'::regclass);
 =   ALTER TABLE public.tech_stacks ALTER COLUMN id DROP DEFAULT;
       public          postgres    false    230    229            ,          0    16495    accounts 
   TABLE DATA           H   COPY public.accounts (id, client_id, login, password, type) FROM stdin;
    public          postgres    false    215   #P       .          0    16500    clients 
   TABLE DATA           V   COPY public.clients (id, fullname, telephone, address, email, is_company) FROM stdin;
    public          postgres    false    217   _P       0          0    16506 
   dev_groups 
   TABLE DATA           :   COPY public.dev_groups (id, name, tech_stack) FROM stdin;
    public          postgres    false    219   �S       2          0    16512 	   employees 
   TABLE DATA           ^   COPY public.employees (id, fullname, birth_date, salary, hire_date, dev_group_id) FROM stdin;
    public          postgres    false    221   ^T       =          0    16582    employees_hardwares 
   TABLE DATA           K   COPY public.employees_hardwares (id, employee_id, hardware_id) FROM stdin;
    public          postgres    false    232   	V       8          0    16528    hardware 
   TABLE DATA           E   COPY public.hardware (id, internet_speed, gpu, cpu, ram) FROM stdin;
    public          postgres    false    227   ,V       4          0    16518    orders 
   TABLE DATA           U   COPY public.orders (id, price, deadline, client_id, creation_date, done) FROM stdin;
    public          postgres    false    223   W       6          0    16522    programs 
   TABLE DATA           V   COPY public.programs (id, repo, name, tech_stack, order_id, dev_group_id) FROM stdin;
    public          postgres    false    225   DX       :          0    16534    tech_stacks 
   TABLE DATA           5   COPY public.tech_stacks (id, stack_name) FROM stdin;
    public          postgres    false    229   [       M           0    0    accounts_id_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public.accounts_id_seq', 4, true);
          public          postgres    false    216            N           0    0    clients_id_seq    SEQUENCE SET     =   SELECT pg_catalog.setval('public.clients_id_seq', 43, true);
          public          postgres    false    218            O           0    0    dev_groups_id_seq    SEQUENCE SET     ?   SELECT pg_catalog.setval('public.dev_groups_id_seq', 6, true);
          public          postgres    false    220            P           0    0    employees_hardwares_id_seq    SEQUENCE SET     H   SELECT pg_catalog.setval('public.employees_hardwares_id_seq', 1, true);
          public          postgres    false    231            Q           0    0    employees_id_seq    SEQUENCE SET     ?   SELECT pg_catalog.setval('public.employees_id_seq', 46, true);
          public          postgres    false    222            R           0    0    orders_id_seq    SEQUENCE SET     <   SELECT pg_catalog.setval('public.orders_id_seq', 29, true);
          public          postgres    false    224            S           0    0    programs_id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public.programs_id_seq', 73, true);
          public          postgres    false    226            T           0    0    tech_eqs_id_seq    SEQUENCE SET     >   SELECT pg_catalog.setval('public.tech_eqs_id_seq', 13, true);
          public          postgres    false    228            U           0    0    tech_stacks_id_seq    SEQUENCE SET     @   SELECT pg_catalog.setval('public.tech_stacks_id_seq', 7, true);
          public          postgres    false    230            �           2606    16549    accounts accounts_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.accounts
    ADD CONSTRAINT accounts_pkey PRIMARY KEY (id);
 @   ALTER TABLE ONLY public.accounts DROP CONSTRAINT accounts_pkey;
       public            postgres    false    215            �           2606    16551    clients clients_pkey 
   CONSTRAINT     R   ALTER TABLE ONLY public.clients
    ADD CONSTRAINT clients_pkey PRIMARY KEY (id);
 >   ALTER TABLE ONLY public.clients DROP CONSTRAINT clients_pkey;
       public            postgres    false    217            �           2606    16553    dev_groups dev_groups_pkey 
   CONSTRAINT     X   ALTER TABLE ONLY public.dev_groups
    ADD CONSTRAINT dev_groups_pkey PRIMARY KEY (id);
 D   ALTER TABLE ONLY public.dev_groups DROP CONSTRAINT dev_groups_pkey;
       public            postgres    false    219            �           2606    16587 ,   employees_hardwares employees_hardwares_pkey 
   CONSTRAINT     j   ALTER TABLE ONLY public.employees_hardwares
    ADD CONSTRAINT employees_hardwares_pkey PRIMARY KEY (id);
 V   ALTER TABLE ONLY public.employees_hardwares DROP CONSTRAINT employees_hardwares_pkey;
       public            postgres    false    232            �           2606    16555    employees employees_pkey 
   CONSTRAINT     V   ALTER TABLE ONLY public.employees
    ADD CONSTRAINT employees_pkey PRIMARY KEY (id);
 B   ALTER TABLE ONLY public.employees DROP CONSTRAINT employees_pkey;
       public            postgres    false    221            �           2606    16557    orders orders_pkey 
   CONSTRAINT     P   ALTER TABLE ONLY public.orders
    ADD CONSTRAINT orders_pkey PRIMARY KEY (id);
 <   ALTER TABLE ONLY public.orders DROP CONSTRAINT orders_pkey;
       public            postgres    false    223            �           2606    16559    programs programs_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.programs
    ADD CONSTRAINT programs_pkey PRIMARY KEY (id);
 @   ALTER TABLE ONLY public.programs DROP CONSTRAINT programs_pkey;
       public            postgres    false    225            �           2606    16561    hardware tech_eqs_pkey 
   CONSTRAINT     T   ALTER TABLE ONLY public.hardware
    ADD CONSTRAINT tech_eqs_pkey PRIMARY KEY (id);
 @   ALTER TABLE ONLY public.hardware DROP CONSTRAINT tech_eqs_pkey;
       public            postgres    false    227            �           2606    16563    tech_stacks tech_stacks_pkey 
   CONSTRAINT     Z   ALTER TABLE ONLY public.tech_stacks
    ADD CONSTRAINT tech_stacks_pkey PRIMARY KEY (id);
 F   ALTER TABLE ONLY public.tech_stacks DROP CONSTRAINT tech_stacks_pkey;
       public            postgres    false    229            �           2606    16627    orders client_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.orders
    ADD CONSTRAINT client_fkey FOREIGN KEY (client_id) REFERENCES public.clients(id) ON DELETE CASCADE;
 <   ALTER TABLE ONLY public.orders DROP CONSTRAINT client_fkey;
       public          postgres    false    223    217    4744            �           2606    16622    employees dev_group_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.employees
    ADD CONSTRAINT dev_group_fkey FOREIGN KEY (dev_group_id) REFERENCES public.dev_groups(id);
 B   ALTER TABLE ONLY public.employees DROP CONSTRAINT dev_group_fkey;
       public          postgres    false    4746    221    219            �           2606    16612    employees_hardwares empl_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.employees_hardwares
    ADD CONSTRAINT empl_fkey FOREIGN KEY (employee_id) REFERENCES public.employees(id);
 G   ALTER TABLE ONLY public.employees_hardwares DROP CONSTRAINT empl_fkey;
       public          postgres    false    4748    221    232            �           2606    16617 !   employees_hardwares hardware_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.employees_hardwares
    ADD CONSTRAINT hardware_fkey FOREIGN KEY (hardware_id) REFERENCES public.hardware(id);
 K   ALTER TABLE ONLY public.employees_hardwares DROP CONSTRAINT hardware_fkey;
       public          postgres    false    4754    227    232            �           2606    16564 #   programs programs_dev_group_id_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.programs
    ADD CONSTRAINT programs_dev_group_id_fkey FOREIGN KEY (dev_group_id) REFERENCES public.dev_groups(id);
 M   ALTER TABLE ONLY public.programs DROP CONSTRAINT programs_dev_group_id_fkey;
       public          postgres    false    225    219    4746            �           2606    16569    programs programs_order_id_fkey    FK CONSTRAINT     �   ALTER TABLE ONLY public.programs
    ADD CONSTRAINT programs_order_id_fkey FOREIGN KEY (order_id) REFERENCES public.orders(id);
 I   ALTER TABLE ONLY public.programs DROP CONSTRAINT programs_order_id_fkey;
       public          postgres    false    4750    225    223            ,   ,   x�3�4�,��/��)��y\���f�Y�Y���8��+F��� -��      .   y  x��T�n�V]_}�C�orGt�U�ad)Q,���";En� 6P7�"pR�n�"K֖
�6�_��G93�,PY����3sΙqEg��-̈́�tn�1�4�˜�X���fZ��¼RA�aE����E���Ҽ@�pd���m�n����K���k3���K:�c���=�㴥�{�ํ_�i��B�-�
\=�¢S�2Gt��od}�3�'�%��}��\��*�O�g*�-s@Wx{�B^�A�d�6�T��ҽ'٠��{Y{���~����8��O\ �<G��-� e#�9T�����^��fD��E�}��O���Q�u�������p�m��6�f�(�w���^_F��,�D gj�jf{�ę�Z����%_:V��^IK�����L�>�Np ���ڙ���#n :��M�f��p�f[�ʳ^;OZ�W����5�bB��Ťa�0���-帞�Q�8�J��8�_�_�{&n`���Tw���P����n&R5܄z&E��%ͷT�$qGQ�z���k������sY{u�UNPa���l�~Ȟj}��*�)]B�k�
A_# ������>ӱ��s�Q�tP�[����2����0�sWUA�/�"
��B\�0w�z���t?�l��]�&�����:ns�pH֟�i���1��Zj<�K���N{0����F�0�wP!Y�\z,�c�zb�FA7�T^��C�r- �^c��x����^{��t�p�)��7o�dK�5r��"08a������(�B�L��L�5^o��i�C^�n�(Q�����x׮G%[ V����ug��3���Z�ϛ�$m$<�̛j��(k���*�ʳ�����=R��g��jqs������$C��PCMoe5~���WU�p      0   f   x�3�OM�L�J�K��Q(JML.�Q��OI�*�2�t��,�,����Q ��E�\���
.�e��y�%�:
�y@m9
�y�y�\����I�9�8̌���� �?%q      2   �  x���MN�0���)r�T��]X�BHpZ �DUXT$6H,����?�0�o���.�FIcO=�<�qK�G����w�S^������y�1�P֘84�qu���F$u���%�I���3<���
��'T­�����BN����W�;^�$	�{�O���9��m	�Ԩ����!��t}6��Q�PY#'��U���)~��92D�L0"m*��j��6m�I�X@��g�
wU9�Mc�n���Qh{�&��D��v�^��u����(S����6�	x1)�����g�m�AX)�ڵ�,4���"n$�p���"�q�͟g��Qe/$[z*m�i#�Av����2g�K��Y[CY���d�&��$|��$J�bR�fR����ӣC�̌��)�%�?���'�:      =      x�3�4�4����� �Z      8   �   x���͊�0�ϓ��p�I���J�� 
�"5`@�R�}��-B������� ��-��K_4]���Iw�x�0V��B���� �X�?���M�1��h6{0Z	�ԣ��7K��}��b�Vʂ�R�HZ�{��<�Ȏ���"[� �O���m��Zb��s���f���s��0]w���8��֊5ش�iV�CS�ͦ�4�5�4m0���U���������#��      4     x���K�� D��]訯�]f='���T)bk0��B�����D��"��ha*$Γ�k��ߥ�kp�7p�\\ppL`�\�`��X��8N���Y������T�?L;f�u�֋�֌�`�QG�W�+�W����_���Er������;��=��"�ܝR�*Xh�ٽu��&�w*v���L���z�&�Pu�t�4�i�o�Dp�g�wn��5�h\���H�<��̖���9���1N��*�+.���ڃN�d�����cǐxQ
��,�JΗa      6   �  x��T�N�0�v��P3Z��\�ƪI+���8�	���U�6x�M��.&M�ڏĆ`��ю�P�R��$�_���|��(�:,�)�k�̞pM�x�=�F�~�'T$��F#��B��D���u��cw&U��2��|1��{��ܚo�������s ��sX]9��6��r�rH�=?��m�����!ӚD1ZDǄ�������q;x=��z��ϸ��L���Ma�>����-���-E�A�Yʒ�f$������<W�R��s�"F�u��l\
��]\
8Wzw֑ezp�-S�X~D���1ޅ�ʊFh���|Q���f��R5W�ehP�S�x�@ˬ��uí�H�I�si~Ug��ށ�~�K����!��5LWg8�R�HNU.M")t!Sd>���������VP������n�������c��<G���Z���E���w�NIƔ����b�0~]�kl�x��(8S$�!Oف0�0 vd�m����"�7?��#�7��`�r�Ye{.e[s��k�V� �;5:x���.�k�'$J9|(о��3��`3�m���~qH���0aJ�d��]b������/O]���c�;)E�3�9��Y���d��K|Р,�V�ؕ�os,��R²2�=!�T�Ep�-���Y.��w?T=W[�s٧%"��T���\��#��Ts�X��4�#�y���t�F���      :   H   x�3�L�J�K��Q(JML.�Q��OI�*�2�,�,�/J��2�,��,��Q(�*�QH�K��K�2������ �     