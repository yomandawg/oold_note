# Table



| id   | title    | genre1 | genre2   | genre 3  |
| ---- | -------- | ------ | -------- | -------- |
| 1    | 어벤져스 | 액션   | 어드벤쳐 | 공상과학 |

* &rarr; 비효율적임



| id   | movie_id | genre_id |
| ---- | -------- | -------- |
| 1    | 1        | 1        |
| 2    | 1        | 2        |
| 3    | 1        | 3        |

* 여러개 있을 때, JSON 표현으로 함
* CSV로 dumping



```json
movies = [
    {
        "id": "1",
        "title": "어벤져스",
        "genres": [1, 2, 3] // M:N relation
    }
]
```

