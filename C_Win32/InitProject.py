import os

# Ŀ¼�б�
directories = [
    'src',
    'src/third_party',
	'build',
	'include',
	'include/third_party',
	'lib',
	'lib/third_party',
	'templates',
	'test',
]

# �����б�, ����Ŀ¼
for dir_name in directories:
    print(f"���ڴ���Ŀ¼: {dir_name}")
    
    os.makedirs(dir_name, exist_ok=True)
    
    print(f"Ŀ¼ '{dir_name}' �����ɹ�")

print("\n��ĿĿ¼�ṹ������!")

